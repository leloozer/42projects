<?php

include "database.php";

try {
	$bdd = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE DATABASE IF NOT EXISTS matcha";
	$bdd->exec($sql);
	$sql = "USE matcha;

CREATE TABLE `user` (
	`login` varchar(20) NOT NULL,
	`score` int(10) NOT NULL,
   `age` int(10) NOT NULL,
  `sexe` int(10),
  `orientation` int(10),
  `passwd` varchar(250) NOT NULL,
  `name` varchar(50) NOT NULL,
  `firstname` varchar(50) NOT NULL,
  `mail` varchar(50) NOT NULL,
  `bio` varchar(250),
  `token` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `image` (
	`id` int(10) UNSIGNED NOT NULL,
	`login` varchar(20) NOT NULL,
	`photo` longblob NOT NULL,
	`profil` int(10) NOT NULL)
	ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `matcha`.`tag` ( `id` INT NOT NULL AUTO_INCREMENT , `name` VARCHAR(50) NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;

CREATE TABLE `matcha`.`user_tag` ( `id` INT(11) NOT NULL AUTO_INCREMENT , `tag_id` INT(11) UNSIGNED NOT NULL , `login` VARCHAR(20) NOT NULL , PRIMARY KEY (`id`)) ENGINE = InnoDB;

ALTER TABLE `user`
	ADD PRIMARY KEY (`login`);
ALTER TABLE `image` 
	ADD PRIMARY KEY(`id`);
ALTER TABLE `image`
	MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;";
	
	$bdd->exec($sql);
	}
catch(PDOException $error)
{
		echo $error->getMessage();
		die();
}
?>
