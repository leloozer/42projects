<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
$_SESSION["logged"] = "";
$login = htmlspecialchars ($_POST['login']);
$pwd = htmlspecialchars ($_POST['passwd']);
$confpass = htmlspecialchars ($_POST['confpass']);
$mail = htmlspecialchars ($_POST['mail']);
$submit = $_POST['submit'];


$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
$query = $bdd->query("SELECT * from user");
while ($log = $query->fetch())
{
	if ($log['login'] === $login)
	{
		echo"<meta http-equiv='refresh' content='1;URL=index.php'>";
		echo"This login already exists\n";
		die;
	}
}

if ($submit != "OK" || $login == NULL || $pwd == NULL || $confpass == NULL || $mail == NULL)
{
	echo"<script>alert('Wrong password and login')</script>";
		echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
	die;	
}
if(!preg_match("/(.+?)@(.+?)\.(.+?)/",$mail))
{
	echo"<script>alert('Wrong mail')</script>";
		echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
	die;
}
if ($pwd !== $confpass)
{
	echo"<script>alert('Bad password confirmation')</script>";
		echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
die;
}
if (!preg_match("/[0-9][a-z]/", $pwd) && !preg_match("/[a-z][0-9]/", $pwd))
{
	echo"<script>alert('Votre password doit avoir au moin une minuscule et un chiffre')</script>";
		echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
die;

}
else
{
	$pwd = hash( 'whirlpool', $pwd);
	$token = uniqid(rand(), true);

	$req = $bdd->prepare('INSERT INTO camagru.user (login, passwd, mail, token) VALUES (:login, :pwd, :mail, :token)');
	$req->execute(array(
		'login' => $login,
		'pwd' => $pwd,
		'mail' => $mail,
		'token' => $token));
	$_SESSION["logged"] = $login;
	mail($mail, "inscription Camagru", "Bravo " . $login . ", tu es inscrit sur Camagru!");
	echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
}
?>
