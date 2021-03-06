<?php

    // configuration
    require("../includes/config.php"); 
    
  
    // Fetch all the records for the user
    $rows = CS50::query("SELECT * FROM portfolios WHERE user_id = ".$_SESSION['id']);
    
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
                "name" => $stock["name"],
                "price" => $stock["price"],
                "shares" => $row["shares"],
                "symbol" => $row["symbol"]
            ];
        }
    }
    
    render("portfolio.php", ["positions" => $positions, "title" => "Portfolio"]);

?>
