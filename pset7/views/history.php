<table class = "table table-striped">
	<tr>
		<th class="text-center">Transaction</th>
		<th class="text-center">Date and Time</th>
		<th class="text-center">Stock</th>
		<th class="text-center">Shares</th>
		<th class="text-center">Price</th>
	</tr>
 
	<?php foreach ($history as $his): ?>
		<tr>
			<td><?= $his["transaction"] ?></td>
			<td><?= $his["timestamp"] ?></td> 
			<td><?= $his["symbol"] ?></td> 
			<td><?= $his["shares"] ?></td> 
			<td><?= $his["price"] ?></td>
		</tr>
	<?php endforeach ?>
</table>
