# Implementasi Linked List Sederhana dalam Bahasa C

Proyek ini adalah contoh implementasi dasar dari struktur data *linked list* (senarai berantai) menggunakan bahasa pemrograman C. Kode ini mendemonstrasikan operasi-operasi fundamental pada linked list, seperti penyisipan di awal, di tengah, dan di akhir.

## Konsep Dasar

-   **Pointer**: Variabel yang menyimpan alamat memori dari variabel lain. Dalam konteks linked list, pointer digunakan untuk menghubungkan satu node dengan node berikutnya.
-   **Linked List**: Struktur data dinamis yang terdiri dari serangkaian *node*. Setiap node berisi data dan sebuah pointer ke node selanjutnya. Node terakhir akan menunjuk ke `NULL`.

## Struktur Node

Struktur data untuk setiap node didefinisikan sebagai berikut:

```c
struct Node {
    int data;           // Data yang disimpan dalam node
    struct Node *next;  // Pointer ke node berikutnya
};
```

## Fungsi yang Diimplementasikan

-   `void insertFirst(struct Node** head_ref, int new_data)`: Menyisipkan node baru di awal (kepala) list.
-   `void insertAfter(struct Node* prev_node, int new_data)`: Menyisipkan node baru setelah node yang ditentukan.
-   `void insertLast(struct Node** head_ref, int new_data)`: Menyisipkan node baru di akhir (ekor) list.
-   `void printList(struct Node *node)`: Mencetak semua elemen dalam list dari awal hingga akhir.

## Cara Kompilasi dan Menjalankan

1.  Pastikan Anda memiliki C compiler (seperti GCC) terinstal.
2.  Buka terminal atau command prompt.
3.  Navigasi ke direktori tempat file `pointer.c` disimpan.
4.  Kompilasi kode dengan perintah:
    ```bash
    gcc pointer.c -o pointer
    ```
5.  Jalankan program yang telah dikompilasi:
    ```bash
    ./pointer
    ```
    Atau di Windows:
    ```bash
    .\pointer.exe
    ```

## Contoh Output

Program akan menghasilkan output yang menunjukkan urutan operasi penyisipan:

```
Menyisipkan 10 dan 20 di akhir (insertLast):
10 -> 20 -> NULL

Menyisipkan 5 di awal (insertFirst):
5 -> 10 -> 20 -> NULL

Menyisipkan 15 setelah node 10 (insertAfter):
5 -> 10 -> 15 -> 20 -> NULL
```
