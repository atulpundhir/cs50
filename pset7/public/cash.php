<?php
    
    require("../includes/config.php"); 
 
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("cash.php", ["title" => "Add Cash"]);
    }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["amount"], $_SESSION["id"]);
        
        cs50::query("INSERT INTO history (user_id, transaction, timestamp, price) VALUES (?, ?, ?,?)", $_SESSION["id"], "CASH", date('Y-m-d h:i:s'), $_POST['amount']);
        
        redirect("/");
       
    }
    
?>
    