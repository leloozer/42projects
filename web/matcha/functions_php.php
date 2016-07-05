<?php

function user_exists($login) {
$bdd = new PDO('mysql:host=localhost;dbname=matcha', 'root', '');
$query = $bdd->query("SELECT * from user");
while ($log = $query->fetch())
{
	if ($log['login'] === $login)
		return true;
}
return false;
}
?>