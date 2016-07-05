<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
$_SESSION["logged"] = "";
$login = htmlspecialchars ($_POST['login']);
$mail = htmlspecialchars ($_POST['mail']);
$submit = $_POST['submit'];
$token = "";

$bdd = new PDO('mysql:host=localhost;dbname=matcha', 'root', '');
$query = $bdd->query("SELECT * from user");

while ($log = $query->fetch())
{
	if ($log['login'] === $login && $log['mail'] != $mail)
	{
		echo "Erreur de login/mail\n";
		echo "<meta http-equiv='refresh' content='1;URL=forget.php'>";
		die;
	}
	if ($log['login'] != $login && $log['mail'] === $mail)
	{
		echo "Erreur de login/mail\n";
		echo "<meta http-equiv='refresh' content='1;URL=forget.php'>";
		die;
	}
	if ($log['login'] === $login && $log['mail'] === $mail)
	{
		$token = $log['token'];
	}
}
if ($token != "")
{
	mail ($mail, "Forgot your Password ?", "Bonjour " . $login . ", clique sur ce lien pour reset ton password: <a href='http://localhost:8080/web/camagru/resetpwd.php?token=". $token ."'>Reset Password</a>", "Content-type:text/html;");
	echo"<meta http-equiv='refresh' content='0;URL=resetpwd.php'>";
}
?>
