<?php 
   
   require "koneksidb.php";

   $ambilrfid	 = $_GET["rfid"];
   $tgl=date("Y-m-d h:i:s");
   $harga_barang = 5000;
   

   $query = mysqli_query($koneksi, "SELECT * FROM tb_daftarrfid WHERE rfid='$ambilrfid'");
   $cek = mysqli_num_rows($query);
   $data = mysqli_fetch_assoc($query);
   $saldo_awal = $data["saldo"];
   $query2 = mysqli_query($koneksi, "SELECT * FROM tb_monitoring WHERE rfid='$ambilrfid'");
   $data2 = mysqli_fetch_assoc($query2);
   $print_hasil = $data2["status_bayar"];

   if ($cek > 0) {
	   
	   if ($saldo_awal > 0){
	   		$hasil_saldo = $saldo_awal - $harga_barang;
	   		if ($hasil_saldo >= 0) {
		   		mysqli_query($koneksi, "UPDATE tb_daftarrfid SET saldo ='$hasil_saldo' WHERE rfid='$ambilrfid'");
		   		$print_hasil = "Transaksi Sukses";
	   		} else {
		   		$print_hasil = "Saldo tidak cukup";
		   		
	   		}
	   } else {
			$print_hasil = "Saldo Tidak Cukup";
	   }

   } else {
	   $status = "ID Belum Terdaftar";
   }
   	  // $data = query("SELECT * FROM tabel_monitoring")[0];
   	  
	   	 	//UPDATE DATA REALTIME PADA TABEL tb_monitoring
	   	  	 $sql      = "UPDATE tb_monitoring SET 
	   	  	              tanggal	= '$tgl',rfid	= '$ambilrfid' , status_bayar = '$print_hasil'";
	   	  	 $koneksi->query($sql);
				  
		     //INSERT DATA REALTIME PADA TABEL tb_save  	
			
			 $sqlsave = "INSERT INTO tb_simpan (tanggal, rfid, saldo)
			 VALUES ('" . $tgl . "', '" . $ambilrfid . "' , '" . saldo ."')";
			 $koneksi->query($sqlsave);

		//MENJADIKAN JSON DATA
		//$response = query("SELECT * FROM tb_monitoring")[0];
		$response = query("SELECT * FROM tb_daftarrfid,tb_monitoring WHERE tb_daftarrfid.rfid='$ambilrfid'" )[0];
      	$result = json_encode($response);
     	echo $result;



 ?>