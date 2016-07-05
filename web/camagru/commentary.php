<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
if ($_SESSION["logged"] === "")
{
	echo "<meta http-equiv='refresh' content='0;URL=gallerie.php'>";
	die();
}
include('header.php');
if (isset($_GET['photo']))
{
	$bdd = new PDO('mysql:host=localhost;dbname=camagru','root', '');
	$photo = $bdd->quote($_GET['photo']);
}
if (isset($_POST['content']))
{
	$body = "Vous avez un nouveau commentaire de" . $_SESSION['logged'];
	preg_match("/'(.+?)-/", $photo, $match);
	$user= $match[1];
	$query = $bdd->query("SELECT * FROM user");
	$user = $query->fetchALL();
	foreach($user as $mail)
	{
		if ($mail['login'] = $user)
			$email = $mail['mail'];
	}
	mail($email, "Nouveau commentaire sur Camagru", $body);
	$content = htmlspecialchars ($_POST['content']);
	$req = $bdd->prepare('INSERT INTO camagru.comments (name, content, image_id) VALUES (:name, :content, :image_id)');
	$req->execute(array(
		'name' => $_SESSION["logged"],
		'content' => $content,
		'image_id' => $_GET['id']
	));
	echo "<meta http-equiv='refresh' content='0;URL=gallerie.php'>";
	die();
}
?>
<div>
	<img src="IMAGE/<?php echo $_GET['photo'];?>" width=50%> 
	<form action="" method="post">
	<div>
		<label for="content">Ecrire un commentaire</label>
		<textarea name="content"></textarea>
	</div>
	<button type="submit">Envoyer</button>
	</form>
	</div>
<?php include("footer.php"); ?>

