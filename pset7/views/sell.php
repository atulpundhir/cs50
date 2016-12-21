<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
             <select class="form-control" name="symbol_id">
             <?php foreach ($shares as $share): ?>
             <option value="<?=$share['id']?>"><?=$share['symbol']?></option>
             <?php endforeach ?>
             </select>
        </div>
        <div class="form-group">
            <button type="submit" class="btn btn-default">SELL</button>
        </div>
    </fieldset>
</form>