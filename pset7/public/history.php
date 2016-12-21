<?php
 
    // configuration
    require("../includes/config.php"); 
 
    $history = CS50::query("SELECT * FROM history WHERE user_id = ? order by id DESC", $_SESSION["id"]);
 
    render("history.php", ["history" => $history, "title" => "History"]);
 
?>