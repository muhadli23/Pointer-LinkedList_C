#include <stdio.h>
#include <stdlib.h> // Diperlukan untuk malloc (alokasi memori)

// --- Penjelasan Pointer dan Linked List ---
// Pointer adalah variabel yang menyimpan alamat memori dari variabel lain.
// Linked list adalah struktur data yang terdiri dari kumpulan node.
// Setiap node berisi data dan sebuah pointer (bernama 'next') ke node berikutnya dalam urutan.
// Node terakhir menunjuk ke NULL, menandakan akhir dari list.
// Pointer 'head' digunakan untuk menyimpan alamat dari node pertama.

// Mendefinisikan struktur untuk sebuah node dalam linked list
struct Node {
    int data;           // Data yang disimpan dalam node
    struct Node *next;  // Pointer ke node berikutnya
};

// Fungsi untuk menyisipkan node baru di awal (paling depan) list
// Menerima double pointer ke head agar bisa mengubah alamat yang disimpan oleh head
void insertFirst(struct Node** head_ref, int new_data) {
    // 1. Alokasikan memori untuk node baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // 2. Masukkan data ke node baru
    new_node->data = new_data;

    // 3. Jadikan 'next' dari node baru sebagai head yang lama
    new_node->next = (*head_ref);

    // 4. Pindahkan head untuk menunjuk ke node baru
    (*head_ref) = new_node;
}

// Fungsi untuk menyisipkan node baru setelah node yang diberikan
void insertAfter(struct Node* prev_node, int new_data) {
    // 1. Cek apakah prev_node (node sebelumnya) adalah NULL
    if (prev_node == NULL) {
        printf("Node sebelumnya tidak boleh NULL\n");
        return;
    }

    // 2. Alokasikan memori untuk node baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // 3. Masukkan data
    new_node->data = new_data;

    // 4. Jadikan 'next' dari node baru sebagai 'next' dari prev_node
    new_node->next = prev_node->next;

    // 5. Pindahkan 'next' dari prev_node untuk menunjuk ke node baru
    prev_node->next = new_node;
}

// Fungsi untuk menyisipkan node baru di akhir list
void insertLast(struct Node** head_ref, int new_data) {
    // 1. Alokasikan memori untuk node baru
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref; // Digunakan untuk traversal

    // 2. Masukkan data
    new_node->data = new_data;

    // 3. Karena ini akan menjadi node terakhir, 'next'-nya adalah NULL
    new_node->next = NULL;

    // 4. Jika linked list masih kosong, jadikan node baru sebagai head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // 5. Jika tidak, jelajahi list sampai ke node terakhir
    while (last->next != NULL) {
        last = last->next;
    }

    // 6. Ubah 'next' dari node terakhir untuk menunjuk ke node baru
    last->next = new_node;
}

// Fungsi untuk mencetak semua elemen dalam linked list dari head
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[]) {
    // Mulai dengan linked list kosong
    struct Node* head = NULL;

    // --- DEMO ---

    // 1. Insert Last (Menyisipkan di akhir)
    printf("Menyisipkan 10 dan 20 di akhir (insertLast):\n");
    insertLast(&head, 10); // List: 10 -> NULL
    insertLast(&head, 20); // List: 10 -> 20 -> NULL
    printList(head);
    printf("\n");

    // 2. Insert First (Menyisipkan di awal)
    printf("Menyisipkan 5 di awal (insertFirst):\n");
    insertFirst(&head, 5); // List: 5 -> 10 -> 20 -> NULL
    printList(head);
    printf("\n");

    // 3. Insert After (Menyisipkan setelah node tertentu)
    // Kita akan menyisipkan 15 setelah node yang berisi data 10.
    // head->next adalah node yang berisi 10.
    printf("Menyisipkan 15 setelah node 10 (insertAfter):\n");
    insertAfter(head->next, 15); // List: 5 -> 10 -> 15 -> 20 -> NULL
    printList(head);
    printf("\n");

    // Membersihkan memori yang dialokasikan (best practice)
    struct Node* current = head;
    struct Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}
