<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
include("header.php");
$ppp = 4;
$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
$qry = $bdd->query("SELECT * FROM comments ORDER BY image_id");
$q = $bdd->query("SELECT * FROM likes WHERE login='$_SESSION[logged]'");
$select = $bdd->query("SELECT COUNT(*) AS total FROM image");
$total_pic = $select->fetch();
$nb_pic = $total_pic[total];
$nb_page = ceil($nb_pic / $ppp);
$comment = $qry->fetchALL();
$likes = $q->fetchALL();

if(isset($_GET['p']))
{
	$cp = intval($_GET['p']);
	if($cp > $nb_page)
	{
		$cp = $nb_page;
	}
	else if ($cp < 1)
	{
		$cp = 1;
	}
}
else
{
	$cp = 1;
}
$first = ($cp - 1) * $ppp;
$query = $bdd->query("SELECT * FROM image ORDER BY id DESC LIMIT $first, $ppp");
$img = $query->fetchALL();

?>
<h5 class="gallerie">Gallerie</h5>
<ul class= "display">
<?php
foreach($img as $photo):
$tmp = 0;
?>
	<li class= "album">
		<p class="namephoto"><?php echo $photo['login'];?><p>
		<img class="img" SRC="IMAGE/<?echo $photo['photo'];?>" width=50%>
		<?php echo $photo['likes']; 
		foreach($likes as $like)
		{
			if ($like['image_id'] === $photo['id'])
				$tmp = 1; 
		}
		?>
			<a href="/web/camagru/like.php?photo=<?php echo  $photo['photo'];?>&id=<?php echo $photo['id']?>">
			<?php 
			if($tmp == 0)
			{
			?>
			Like
			<?php 
			} 
			else 
			{
			?>
			Dislike
			<?php
			}
			?>
			</a>
		<div>
	<?php
		foreach($comment as $com)
		{
			if ($com['image_id'] == $photo['id'])
			{
				echo "<h4 class='namecomment'>" . $com['name'] . "</h4>";
				echo "<div class='comment'>" . $com['content'] . "</div>";
			}
		}
	?>
		</div>
		<a href="/web/camagru/commentary.php?photo=<?php echo $photo['photo'];?>&id=<?php echo $photo['id']?>">Comment</a>
	</li>
	<?php endforeach; ?>
</ul>
<div class= "page">

		<p><?php 
			if ($cp > 1) { 
				echo ' <a href="gallerie.php?p='. ($cp - 1) . '">previous</a>'; 
			} ?> [ <?php echo $cp; ?> ] <?php
			if ($cp < $nb_page) {
				echo ' <a href="gallerie.php?p='. ($cp + 1) . '">next</a>';
			}?>
		</p>
</div>
<?PHP include("footer.php"); ?>

