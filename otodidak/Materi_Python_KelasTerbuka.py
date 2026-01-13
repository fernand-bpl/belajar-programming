====================Materi Pertemuan Ke-3====================
--------------------Cara Kerja Program dan Bytecode--------------------
import time
start_time = time.time()
print ("Hello, World!")
print ("This is a test file.")

print ("Testing complete.")

# ini adalah komentar dalam bahasa indonesia
"""contoh komentar 
multi-baris dalam bahasa indonesia"""

a = 10 # menetapkan nilai 10 ke varia
print ("Nilai a adalah:", a)
print (time.time () - start_time, "detik")
#kita bisa mengompile python ke bytecode menggunakan perintah:
"""cara mengcompile python ke bytecode: buka terminal 
lalu ketik: python -m py_compile TEST.py, maka
akan terbentuk file __pycache__/TEST.cpython-XX.pyc"""
#tetapi perbedaan kecepatannya hanya dikit, ini akan bermanfaat pada big code


====================Materi Pertemuan Ke-4====================
--------------------Mengenal Variabel--------------------
# variabel adalah tempat menyimpan data

# assigment nilai
a = 10
x = 5
panjang = 1000

# pemanggilan pertama
print ("Nilai a =", a)
print ("Nilai a =", x)
print ("Nilai a =", panjang)

# penamaan
nilai_y = 15 # dengan menggunakan underscore
juta10 = 10000000 
nilaiZ = 17.5

# pemanggilan kedua
print ("Nilai a =", a)
a = 7
print ("Nilai a =", a)


# assigment indirect
b = a
print ("Nilai b =", b)


====================Materi Pertemuan Ke-5====================
--------------------Tipe Data--------------------
# a = 1=, a adalah variabel dengan nilai 10
# tipe data: Angka satuan (integer)
data_integer = 1 
print (type(data_integer))
print("data : ", data_integer)
print ("bertipe : ", type(data_integer))

# tipe data: angka dengan koma (float)
data_float = 1.5
print("data : ", data_float)
print ("bertipe : ", type(data_float))

# tipe data: kumpulan karakter (string)
data_string = "ucup 10"
print("data : ", data_string)
print ("bertipe : ", type(data_string))

# tipe data: biner true/false (boolean)
data_bool = True
print("data : ", data_bool)
print ("bertipe : ", type(data_bool))

## tipe data khusus
# bilangan kompleks
data_complex = complex(5, 6)
print("data : ", data_complex)
print ("bertipe : ", type(data_complex))

# tipe data dari bahasa C
from ctypes import c_double, c_char
data_c_double = c_double (10.5)
print("data : ", data_c_double)
print ("bertipe : ", type(data_c_double))


====================Materi Pertemuan Ke-6====================
--------------------Casting Tipe Data--------------------
# merubah dari stu tipe ke tipe lain
#  tipe data = int, float, str, bool


# INTEGER
print ("=====INTEGER====")
data_int = 9
print ("data=", data_int, "type=", type(data_int))

data_float = float(data_int)
data_str = str(data_int)
data_bool = bool(data_int) # akan false jika nilai int = 0 
print ("data=", data_float, "type=", type(data_float))
print ("data=", data_str, "type=", type(data_str))
print ("data=", data_bool, "type=", type(data_bool))


# FLOAT
print ("=====FLOAT====")
data_float = 9.9
print ("data=", data_float, "type=", type(data_float))

data_int = int(data_float) # akan dibulatkan ke bawah
data_str = str(data_float)
data_bool = bool(data_float) # akan false jika nilai float = 0 
print ("data=", data_int, "type=", type(data_int))
print ("data=", data_str, "type=", type(data_str))
print ("data=", data_bool, "type=", type(data_bool))

# BOOLEAN
print ("=====BOOLEAN====")
data_bool = True
print ("data=", data_bool, "type=", type(data_bool))

data_int = int(data_bool) # akan dibulatkan ke bawah
data_str = str(data_bool)
data_float =float(data_bool) # akan false jika nilai float = 0 
print ("data=", data_int, "type=", type(data_int))
print ("data=", data_str, "type=", type(data_str))
print ("data=", data_float, "type=", type(data_float))

# STRING
print ("=====STR====")
data_bool = "False"
print ("data=", data_bool, "type=", type(data_bool))

data_int = int(data_bool) # str harus angka
data_float =float(data_bool) #str harus angka
data_bool = bool(data_bool) # false jika string kosong
print ("data=", data_int, "type=", type(data_int))
print ("data=", data_float, "type=", type(data_float))
print ("data=", data_bool, "type=", type(data_bool))


====================Materi Pertemuan Ke-7====================
--------------------Mengambil Input data dari User--------------------
# setiap data yang dimasukkan adalah string
data = input("Masukan data: ")
print("data =",data,",type =",type(data))

# jika kita ingin mengambil int, maka
angka = float(input("Masukan angka: "))
angka = int(input("Masukan angka: "))
print("data =", angka, ",type =", type(angka))

# bagaimana dengan boolean
biner = bool(int(input("masukan nilai boolean: ")))
print("data =", biner, ",type =", type(biner))


====================Materi Pertemuan Ke-8====================
--------------------Operasi Aritmatika--------------------
a = 10
b = 3

# operasi tambah
hasil = a + b
print(a,'+',b,'=',hasil)

# operasi pengurangan
hasil = a - b
print(a,'-',b,'=',hasil)

# operasi perkalian
hasil = a * b
print(a,'*',b,'=',hasil)

# operasi pembagian
hasil = a / b
print(a,'/',b,'=',hasil)

# operasi eksponen (pangkat)
hasil = a ** b
print(a,'**',b,'=',hasil)

# operasi modulus
hasil = a % b
print(a,'%',b,'=',hasil)

# operasi floor division (pembagian tetapi dibulatkan kebawah)
hasil = a // b
print(a,'//',b,'=',hasil)

# prioritas operasi, operational precedence
x = 3
y = 2
z = 4

hasil = x ** y * z + x / y - y % z // x
# haislnya = 37.5 
print(x,'**',y,'*',z,'+',x,'/',y,'-',y,'%',z,'//',x,'=',hasil)

hasil = x + y * z
print(x,'+',y,'*',z,'=',hasil)

hasil = (x + y) * z
print('(',x,'+',y,')*',z,'=',hasil)


====================Materi Pertemuan Ke-9====================
--------------------Latihan Perghitungan Sederhana--------------------
#latihan konversi satuan temperature

#program konversi celscius ke satuan lain
print("\nprogram konversi temperature\n")

celcius = float(input("masukan suhu dalam celcius: "))
print("suhu adalah ",celcius, " celcius")

#reamur
reamur = (4/5) * celcius
print("suhu dalam reamur adalah ", reamur, " reamur")

#fahrenheit
fahrenheit = (9/5) * celcius + 32
print("suhu dalam fahrenheit adalah ", fahrenheit, " fahrenheit")

#kelvin
kelvin = celcius + 273
print("suhu dalam kelvin adalah ", kelvin, " kelvin")

################# TUGAS PR #################
#membuat fahrenheit ke kelvin dan kelvin ke fahrenheit dengan menggunakan perantara (celcius)
print("\nprogram konversi temperature fahrenheit ke kelvin dan kelvin ke fahrenheit\n")

print("Konversi fahrenheit ke kelvin")
fahrenheit = float(input("Masukkan suhu dalam fahrenheit: "))

# konversi ke celcius
celcius = (5/9) * (fahrenheit - 32)
# konversi ke kelvin
kelvin = celcius + 273
print("Suhu dalam kelvin adalah", kelvin, "kelvin")

print("\nKonversi kelvin ke fahrenheit")
kelvin = float(input("Masukkan suhu dalam kelvin: "))

# konversi ke celcius
celcius = kelvin - 273
# konversi ke fahrenheit
fahrenheit = (9/5) * celcius + 32
print("Suhu dalam fahrenheit adalah", fahrenheit, "fahrenheit")

====================Materi Pertemuan Ke-10====================
--------------------Operasi Komparasi--------------------
#operasi komparasi

# setiap hasil dari operasi komparasi adalah boolean

# >, <, >=, <=, ==, !=, is, is not

a = 4
b = 2

#lebih besar dari (>)
print('========== LEBIH BESAR DARI > ==========')
hasil = a > 3
print(a,'>',3,'=',hasil)
hasil = b > 3
print(b,'>',3,'=',hasil) 
hasil = b > 2
print(b,'>',2,'=',hasil)

# kurang dari (<)
print('========== KURANG DARI < ==========')
hasil = a < 3
print(a,'<',3,'=',hasil)
hasil = b < 3
print(b,'<',3,'=',hasil) 
hasil = b < 2
print(b,'<',2,'=',hasil)

# LEBIH DARI SAMA DENGAN (>=)
print('========== LEBIH DARI SAMA DENGAN >= ==========')
hasil = a >= 3
print(a,'>=',3,'=',hasil)
hasil = b >= 3
print(b,'>=',3,'=',hasil) 
hasil = b >= 2
print(b,'>=',2,'=',hasil)

# KURANG DARI SAMA DENGAN (>=)
print('========== KURANG DARI SAMA DENGAN <= ==========')
hasil = a <= 3
print(a,'<=',3,'=',hasil)
hasil = b <= 3
print(b,'<=',3,'=',hasil) 
hasil = b <= 2
print(b,'<=',2,'=',hasil)

# SAMA DENGAN (==)
print('========== SAMA DENGAN == ==========')
hasil = a == 4
print(a,'==',4,'=',hasil)
hasil = b == 4
print(b,'==',4,'=',hasil) 
hasil = b == 2
print(b,'==',2,'=',hasil)

# TIDAK SAMA DENGAN (!=)
print('========== TIDAK SAMA DENGAN != ==========')
hasil = a != 4
print(a,'!=',4,'=',hasil)
hasil = b != 4
print(b,'!=',4,'=',hasil) 
hasil = b != 2
print(b,'!=',2,'=',hasil)

# is (identitas)
print('========== IDENTITAS is ==========')
x = 5 # membuat object x
y = 5 # membuat object y
print('nilai x =',x,',id = ',hex(id(x)))
print('nilai y =',y,',id = ',hex(id(y)))
hasil = x is y
print('x is y =',hasil)

y = 6 # membuat object y
hasil = x is y
print('x is y =',hasil)

x = 5 # membuat object x
y = 6 # membuat object y
print('nilai x =',x,',id = ',hex(id(x)))
print('nilai y =',y,',id = ',hex(id(y)))
hasil = x is y
print('x is y =',hasil)

y = 7 # membuat object y
hasil = x is y
print('x is y =',hasil)

# is not (negasi identitas)
print('========== NEGASI IDENTITAS is not ==========')
x = 5 # membuat object x
y = 5 # membuat object y
print('nilai x =',x,',id = ',hex(id(x)))
print('nilai y =',y,',id = ',hex(id(y)))
hasil = x is not y
print('x is not y =',hasil)

y = 6 # membuat object y
hasil = x is not y
print('x is not y =',hasil)

====================Materi Pertemuan Ke-11====================
--------------------Operasi Logika atau Boolean--------------------


====================Materi Pertemuan Ke-12====================
--------------------Latihan Komparasi dan Logika--------------------


====================Materi Pertemuan Ke-13====================
--------------------Operasi Bitwise--------------------


====================Materi Pertemuan Ke-14====================
--------------------Operasi Assigment--------------------


====================Materi Pertemuan Ke-15====================
--------------------Pengenalan String--------------------\


====================Materi Pertemuan Ke-16====================
--------------------F--------------------


====================Materi Pertemuan Ke-17====================
--------------------F--------------------


====================Materi Pertemuan Ke-18====================
--------------------F--------------------


====================Materi Pertemuan Ke-19====================
--------------------F--------------------


====================Materi Pertemuan Ke-20====================
--------------------F--------------------