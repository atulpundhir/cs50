<?php
    require("../includes/config.php"); 
 
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("buy.php", ["title" => "Buy"]);
    }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    
        $stock = lookup($_POST["symbol"]);
     
        if ($stock === false)
        {
            apologize("The stock entered could not be found");
        }
 
        $cash_sql = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        
        $cash = $cash_sql[0]['cash'];
 
        if ($cash < $_POST["shares"] * $stock["price"])
        {
            apologize("Oops !!! Dont have sufficient Balance ... Sell few..");
        }

        cs50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $_POST["shares"]*$stock["price"], $_SESSION["id"]);
 
        cs50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], strtoupper($_POST["symbol"]), $_POST["shares"]);
        
        cs50::query("INSERT INTO history (user_id, transaction, timestamp, symbol, shares, price) VALUES (?, ?, ?, ?, ?, ?)", $_SESSION["id"], "BUY", date('Y-m-d h:i:s'), strtoupper($_POST["symbol"]), $_POST["shares"], $stock["price"]);
        
        redirect("/");
        
    }

?>