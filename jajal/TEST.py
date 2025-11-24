import random

angka_rahasia = random.randint(1, 10)
tebakan = int(input("Tebak angka antara 1 sampai 10: "))

if tebakan == angka_rahasia:
    print("Selamat! Tebakanmu benar.")
else:
    print(f"Maaf, salah. Angka yang benar adalah {angka_rahasia}.")
