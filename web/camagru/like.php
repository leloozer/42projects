<?php

if (session_status() != PHP_SESSION_ACTIVE) session_start();
if ($_SESSION[logged] == "")
{
	echo "<meta http-equiv='refresh' content='0;URL=gallerie.php>";
	die();
}

function addlike()
{
$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
$photo = $bdd->quote($_GET['photo']);
$like = $bdd->query("SELECT * FROM image WHERE photo='$_GET[photo]'");
$likes=$like->fetch();
$nblikes = $likes['likes'] + 1;
$name = $_GET['photo'];
$req = $bdd->prepare("UPDATE image  SET likes=:likes WHERE photo=:photos");
$req->bindParam(":likes", $nblikes);
$req->bindParam(":photos", $name);
$req->execute();
}

function dislike()
{
$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
$photo = $bdd->quote($_GET['photo']);
$like = $bdd->query("SELECT * FROM image WHERE photo='$_GET[photo]'");
$likes=$like->fetch();
$nblikes = $likes['likes'] - 1;
$name = $_GET['photo'];
$req = $bdd->prepare("UPDATE image  SET likes=:likes WHERE photo=:photos");
$req->bindParam(":likes", $nblikes);
$req->bindParam(":photos", $name);
$req->execute();
}

$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
$query = $bdd->query("SELECT * FROM likes WHERE login='$_SESSION[logged]'");
$q = $query->fetchALL();
foreach ($q as $lks)
{
	if ($_GET['id'] === $lks['image_id'])
	{
		$delete = $bdd->query("DELETE FROM likes WHERE id='$lks[id]'");
		dislike();
		echo"<meta http-equiv='refresh' content='0;URL=gallerie.php'>";
		die();
	}
}

$req = $bdd->prepare('INSERT INTO camagru.likes (login, image_id) VALUES (:login, :image_id)');
$req->execute(array(
	'login'=> $_SESSION['logged'],
	'image_id'=> $_GET['id']));
	addlike();
echo"<meta http-equiv='refresh' content='0;URL=gallerie.php'>";
?>
