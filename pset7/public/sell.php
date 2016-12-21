<?php
    require("../includes/config.php"); 
 
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        
        $shares = CS50::query("SELECT id,symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        
        render("sell.php", ["shares" => $shares, "title" => "Sell"]);
        
       
    }
    
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
    
        $shares = CS50::query("SELECT symbol,shares FROM portfolios WHERE id = ?", $_POST["symbol_id"]);
         
        $stock = lookup($shares[0]["symbol"]);
        $price = $shares[0]['shares'] * $stock['price'];
        
    
        CS50::query("DELETE FROM portfolios WHERE id = ? ", $_POST["symbol_id"]);
   
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $price, $_SESSION["id"]);
 
        CS50::query("INSERT INTO history (user_id, transaction, timestamp, symbol, shares, price) VALUES (?, ?, ?, ?, ?, ?)", $_SESSION["id"], "SELL", date('Y-m-d h:i:s'), strtoupper($shares[0]["symbol"]), $shares[0]['shares'], $stock["price"]);
 
        redirect("/");
        
    }

?>