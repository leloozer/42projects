<?php
$login = htmlspecialchars ($_POST['login']);
$token = htmlspecialchars ($_POST['token']);
$newpwd = htmlspecialchars ($_POST['pwd']);
$confnewpwd = htmlspecialchars ($_POST['confpwd']);
$submit = $_POST['submit'];

$bdd = new PDO('mysql:host=localhost;dbname=camagru', 'root', '');
$query = $bdd->query("SELECT * form user");

if (($_POST['pwd'] == NULL) || ($_POST['confpwd'] == NULL))
{
	echo"Valeur NULL envoyee\n";
	echo"<meta http-equiv='refresh' content='1;URL=resetpwd.php'>";
die;
}
else
{
	if ($newpwd !== $confnewpwd)
	{
		echo"Mauvaise confirmation du mot de passe\n";
		echo"<meta http-equiv='refresh' content='1;URL=resetpwd.php'>";
die;
	}
	$newpwd = hash('whirlpool', $newpwd);
	while ($log = $query->fetch)
	{
		if ($log['login'] === $login && $log['token'] === $token)
		{
			$token = uniqid(rand(), true);
			$req = $bdd->prepare("UPDATE camagru.user SET passwd= :passwd, token= :token WHERE login='$login'");
			$req->execute(array(
				'passwd' => $newpwd,
				'token' => $token));
			$_SESSION["logged"] = $login;
		}
	}	
			echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
}
?>
