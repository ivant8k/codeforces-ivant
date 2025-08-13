import sys

def solve():
    """
    Solves the Completely Divisible Subarrays problem efficiently.
    """
    # Membaca input dengan lebih cepat
    n, k = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))

    # freq adalah dictionary (hash map) untuk menyimpan frekuensi sisa bagi.
    # Kunci: (jumlah_prefix % k)
    # Nilai: seberapa sering sisa bagi tersebut muncul
    freq = {}

    # Inisialisasi untuk prefix kosong (sebelum array dimulai).
    # Jumlah elemen habis dibagi K adalah 0, sisa baginya (0 % k) adalah 0.
    # Ini penting untuk menghitung sub-array yang dimulai dari indeks 0.
    freq[0] = 1

    ans = 0
    current_count = 0

    # Iterasi melalui setiap elemen di array
    for x in a:
        # Perbarui jumlah elemen yang habis dibagi k sejauh ini
        if x % k == 0:
            current_count += 1
        
        # Kita mencari prefix sebelumnya (sebut saja P_i) sehingga
        # (current_count - P_i) % k == 0, yang berarti
        # current_count % k == P_i % k.
        rem = current_count % k
        
        # Jumlah sub-array valid yang berakhir di sini adalah sama dengan
        # jumlah prefix sebelumnya yang memiliki sisa bagi yang sama.
        ans += freq.get(rem, 0)
        
        # Perbarui peta frekuensi dengan sisa bagi dari prefix saat ini.
        freq[rem] = freq.get(rem, 0) + 1
        
    print(ans)

solve()