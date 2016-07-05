<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
<script type="text/javascript" src="js/jquery.autocomplete.min.js"></script>


<style>
body { font-family: Arial; }
.autocomplete-suggestions { border: 1px solid #999; background: #FFF; overflow: auto; }
.autocomplete-suggestion { padding: 2px 5px; white-space: nowrap; overflow: hidden; }
.autocomplete-selected { background: #F0F0F0; }
.autocomplete-suggestions strong { font-weight: normal; color: #3399FF; }
</style>

<script type="text/javascript">
$(document).ready(function() {
	$('#tag').autocomplete({
		serviceUrl: 'tag2.php',
			dataType: 'json'
	});
});
</script>

<? if (isset($_POST['tag']))
{
	$newtag = htmlspecialchars($_POST[tag]);
	if (!preg_match("/[#](.+?)/", $newtag))
	{
		echo"<script>alert('Votre tag doit commencer par un #.')</script>";
		echo"<meta http-equiv='refresh' content='0;URL=myprofil.php'>";
		die();
	}
	$query = $bdd->query("SELECT * FROM tag");
	$all = $query->fetchALL();
	foreach($all as $alltag)
	{
		if ($alltag[name] == $newtag)
		{
			$qr = $bdd->query("SELECT * FROM user_tag WHERE login='$_SESSION[logged]'");
			$exist = $qr->fetchALL();
			foreach ($exist as $existag)
			{
				if ($existag[tag_id] === $alltag[id])
				{		
					echo"<script>alert('Vous avez deja utilise ce tag.')</script>";
					echo"<meta http-equiv='refresh' content='0;URL=myprofil.php'>";
					die();
				}
			}
			$req = $bdd->prepare('INSERT INTO matcha.user_tag (tag_id, login) VALUES (:tag_id, :login)');
			$req->execute(array(
				'tag_id' => $alltag[id],
				'login' => $_SESSION[logged]));
			echo "<meta http-equiv='refresh' content='0;URL=myprofil.php'>";
			die();
		}
	}
	$req = $bdd->prepare('INSERT INTO matcha.tag (name) VALUES (:name)');
	$req->execute(array('name' => $newtag));
	$query = $bdd->query("SELECT * FROM tag WHERE name='$newtag'");
	$tag = $query->fetchALL();
	foreach($tag as $thetag){}
	$req = $bdd->prepare('INSERT INTO matcha.user_tag (tag_id, login) VALUES (:tag_id, :login)');
	$req->execute(array(
		'tag_id' => $thetag[id],
		'login' => $_SESSION[logged]));
	echo "<meta http-equiv='refresh' content='0;URL=myprofil.php'>";
	die();
}

?>

<?php 
$bdd = new PDO('mysql:host=localhost;dbname=matcha', 'root', '');
$quser_tag = $bdd->query("SELECT * FROM user_tag WHERE login='$_SESSION[logged]'");
$ustag = $quser_tag->fetchALL();
foreach($ustag as $idtag)
{
	$qtag = $bdd->query("SELECT * FROM tag WHERE id='$idtag[tag_id]'");
	$tag = $qtag->fetch();
	echo $tag[name];
}
?>


<form action="" method="POST">
Tapez votre tag :<input type="text" name="tag" id="tag"/>
<input type="submit" value="ajouter"/>
</form> 
