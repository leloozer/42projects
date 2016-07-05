<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();

function auth($login, $passwd)
{
	$bdd = new PDO('mysql:host=localhost;dbname=matcha', 'root', '');
	$query = $bdd->query("SELECT * FROM user");
	$passwd = hash('whirlpool', $passwd);
	while ($log = $query->fetch())
	{
		if (($log["login"] === $login) && ($log ["passwd"] === $passwd))
			return TRUE;	
	}
	return FALSE;
}
$login = htmlspecialchars ($_POST["login"]);
$passwd = htmlspecialchars ($_POST["passwd"]);
	if (auth($login, $passwd) == TRUE)
	{
		$_SESSION["logged"] = $login;
		echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
	}
	else if (auth($login, $passwd) == FALSE)
	{
		$_SESSION["logged"] = "";
		echo"<script>alert('Votre Login/Pasword n'est pas valide')</script>";
		echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
	die;
	}

