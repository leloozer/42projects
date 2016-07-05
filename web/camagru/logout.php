<?php
if (session_status() != PHP_SESSION_ACTIVE) session_start();
include("user_functions.php");
unset($_SESSION["logged"]);
session_destroy();
echo"<meta http-equiv='refresh' content='0;URL=index.php'>";
?>
