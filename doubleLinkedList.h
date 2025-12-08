#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream> // hanya untuk contoh output/error sederhana

template<typename T>
class DoubleLinkedList {
  public:
      struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t sz;

    // konstruktor
    DoubleLinkedList() : head(nullptr), tail(nullptr), sz(0) {}

    // destruktor
    ~DoubleLinkedList() {
        clear();
    }

    // kosongkan list
    void clear() {
        Node* cur = head;
        while (cur) {
            Node* n = cur->next;
            delete cur;
            cur = n;
        }
        head = tail = nullptr;
        sz = 0;
    }

    // jumlah elemen
    size_t size() const { return sz; }

    // ----------------------
    // Tambah data di akhir
    // ----------------------
    void tambahData(const T& value) {
        Node* node = new Node(value);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        ++sz;
    }

    // ------------------------------------------------
    // Hapus data berdasarkan indeks (0..size-1)
    // mengembalikan true jika berhasil
    // ------------------------------------------------
    bool hapusData(size_t index) {
        if (index >= sz) return false;
        Node* cur;
        // pilih arah traversal yang lebih cepat
        if (index < sz / 2) {
            cur = head;
            for (size_t i = 0; i < index; ++i) cur = cur->next;
        } else {
            cur = tail;
            for (size_t i = sz - 1; i > index; --i) cur = cur->prev;
        }

        Node* p = cur->prev;
        Node* n = cur->next;
        if (p) p->next = n; else head = n;
        if (n) n->prev = p; else tail = p;

        delete cur;
        --sz;
        return true;
    }

    // ------------------------------------------------
    // Ambil (edit) data: mengembalikan pointer ke data
    // Jika index invalid -> nullptr
    // Caller dapat melakukan perubahan *langsung* pada data:
    //   T* p = list.editData(i); if (p) p->field = newVal;
    // ------------------------------------------------
    T* editData(size_t index) {
        if (index >= sz) return nullptr;
        Node* cur;
        if (index < sz / 2) {
            cur = head;
            for (size_t i = 0; i < index; ++i) cur = cur->next;
        } else {
            cur = tail;
            for (size_t i = sz - 1; i > index; --i) cur = cur->prev;
        }
        return &cur->data;
    }

    // ------------------------------------------------
    // Update data: ganti seluruh elemen pada index dengan value baru
    // mengembalikan true jika berhasil
    // ------------------------------------------------
    bool updateData(size_t index, const T& value) {
        T* p = editData(index);
        if (!p) return false;
        *p = value;
        return true;
    }
};

#endif // DOUBLELINKEDLIST_H
