
# FP_SISOP20_E08
Achmad Zidan Akbar / 05111840000005

M RIDHO DAFFA ARDISTA / 05111840000065

<h3>Note </h3>  

***Kendala:***
 -  Kendala, kami tidak memahami cara kerja XV6 secara benang merah.   
 -  Library Standart C (libgcc) tidak disupport, sehingga kami menggunakan XV6- FreeBSD.
 -  Fungsi Stat masih belum digarap
  
 ***Keterangan***
 - Semua File telah terlampir dokumentasi penjelasan. 
 - Kebanyakan code didapat dari codingan yang sudah ada, copyright tertera pada file.

 
 <h2>Cara Menjalankan Command</h2>
Install XV6-FreeBsd, dengan clone repo, lalu build source code-nya.
	

    git clone https://github.com/DoctorWkt/xv6-freebsd.git
 lalu build (MakeFile) pada folder xv6_freebsd dengan perintah.    *syarat menggunakan libgcc.a 32bit

    make
copy kan folder yang ada pada repo ini di directory cmd. lalu build lagi (dapat menggunakan qemu)

    make qemu
Command dapat digunakan. contoh:

    factor 23
   output : 
   
    factor 23 : 23

  
