<?php

include "database.php";

try {
	$bdd = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE DATABASE IF NOT EXISTS camagru";
	$bdd->exec($sql);
	$sql = "USE camagru;

CREATE TABLE `image` (
  `id` int(10) UNSIGNED NOT NULL,
  `login` varchar(20) NOT NULL,
  `photo` longblob NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `user` (
  `login` varchar(20) NOT NULL,
  `passwd` varchar(250) NOT NULL,
  `mail` varchar(50) NOT NULL,
  `token` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `comments` (
	`id` int(11) NOT NULL,
	`name` varchar(20) NOT NULL,
	`content` longtext NOT NULL,
	`image_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `camagru`.`likes` ( 
	`id` INT UNSIGNED NOT NULL AUTO_INCREMENT , 
	`login` VARCHAR(20) NOT NULL , 
	`image_id` INT NOT NULL , PRIMARY KEY (`id`)
) ENGINE = InnoDB;

ALTER TABLE `image`
  ADD PRIMARY KEY (`id`);
ALTER TABLE `comments`
  ADD PRIMARY KEY (`id`);
ALTER TABLE `user`
	ADD PRIMARY KEY (`login`);
ALTER TABLE `image`
	MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;
ALTER TABLE `comments`
	MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT;
ALTER TABLE `image` 
	ADD `likes` INT UNSIGNED NOT NULL AFTER `photo`;";
	$bdd->exec($sql);
	}
catch(PDOException $error)
{
		echo $error->getMessage();
		die();
}
?>
