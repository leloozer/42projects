<?php

if (isset($_GET[delete]))
{
	$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
	$query = $bdd->query("SELECT * FROM image WHERE photo='$_GET[delete]'");
	$image = $query->fetch();
	if ($image[login] === $_SESSION[logged])
	{
		unlink(IMAGE. '/' . $image[photo]);
		$bdd->query("DELETE FROM image WHERE photo='$_GET[delete]'");
		echo"<meta http-equiv='refresh' content='0;URL=shooting.php'>";
		die();
	}
}


$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
$query = $bdd->query("SELECT * FROM image WHERE login='$_SESSION[logged]' ORDER BY id");
$img = $query->fetchAll();
?>
<h5 class="gallerie">Mon Album</h5>
<ul class="album">
<?php
foreach($img as $photo) :
?>
	<li>
		<img class="img" SRC="IMAGE/<?echo $photo['photo'];?>" width=30%>
		<a href="?delete=<?echo $photo['photo']?>">Deleted</a>
	</li>
	<?php endforeach; ?>
</ul>
