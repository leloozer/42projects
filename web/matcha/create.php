<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
$_SESSION["logged"] = "";
$login = htmlspecialchars ($_POST['login']);
$name = htmlspecialchars ($_POST['name']);
$firstname = htmlspecialchars ($_POST['firstname']);
$pwd = htmlspecialchars ($_POST['passwd']);
$confpass = htmlspecialchars ($_POST['confpass']);
$mail = htmlspecialchars ($_POST['mail']);
$age = htmlspecialchars ($_POST['age']);
$submit = $_POST['submit'];


$bdd = new PDO('mysql:host=localhost;dbname=matcha', 'root', '');
$query = $bdd->query("SELECT * from user");
while ($log = $query->fetch())
{
	if ($log['login'] === $login)
	{
		echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
		echo"This login already exists\n";
		die();
	}
}

if ($submit != "OK" || $login == NULL || $pwd == NULL || $confpass == NULL || $mail == NULL || $name == NULL || $firstname == NULL)
{
	echo"<script>alert('Wrong password and login')</script>";
	echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
	die;	
}
if(is_numeric($age) == FALSE || $age > 100)
{
	echo"<script>alert('Entrez un age valide comprit entre 0 et 100')</script>";
	echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
	die;		
}

if(!preg_match("/(.+?)@(.+?)\.(.*)/",$mail))
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
else
{
	$pwd = hash( 'whirlpool', $pwd);
	$token = uniqid(rand(), true);

	$req = $bdd->prepare('INSERT INTO matcha.user (login, score, age, passwd, mail, name, firstname, token) VALUES (:login, :score, :age, :pwd, :mail, :name, :firstname, :token)');
	$req->execute(array(
		'login' => $login,
		'score' => 0,
		'age' => $age,
		'pwd' => $pwd,
		'mail' => $mail,
		'name' => $name,
		'firstname' => $firstname,
		'token' => $token));
	$_SESSION["logged"] = $login;
	mail($mail, "inscription Matcha", "Bravo " . $login . ", tu es inscrit sur Matcha!");
	echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
}
?>
