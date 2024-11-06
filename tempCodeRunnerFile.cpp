#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *left;
    struct node *right;
};
typedef struct node node;

// node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void tranverse(node *head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node **head);
void jumlahData(node **head);
void totalData(node **head);

//========================================================

int main()
{
    node *head;
    int pilih;

    head = NULL;
    do
    {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list \n");
        printf("4. Cetak isi list\n");
        printf("5. Hapus data di awal\n");
        printf("6. Hapus data ditengah list\n");
        printf("7. Hapus data di akhir list\n");
        printf("8. Cari data didalam list\n");
        printf("9. Jumlah data didalam list\n");
        printf("10. Hasil penjumlahan semua data dalam list\n");

        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);
        if (pilih == 1)
            tambahAwal(&head);
        else if (pilih == 2)
            tambahData(&head);
        else if (pilih == 3)
            tambahAkhir(&head);
        else if (pilih == 4)
        {
            tranverse(head);
            getch();
        }
        else if (pilih == 5)
            hapusAwal(&head);
        else if (pilih == 6)
            hapusData(&head);
        else if (pilih == 7)
            hapusAkhir(&head);
        else if (pilih == 8)
            cariData(&head);
        else if (pilih == 9)
            jumlahData(&head);
        else if (pilih == 10)
            totalData(&head);

    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head)
{
    int bil;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->right = *head;
        pNew->left = NULL;

        if (*head != NULL)
        {
            (*head)->left = pNew;
        }

        *head = pNew;
    }
    else
    {
        printf("Alokasi memori gagal");
        getch();
    }
}

//========================================================

void tambahData(node **head)
{
    int pos, bil;
    int count = 1;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nLetak penyisipan pada urutan data ke- : ");
    fflush(stdin);
    scanf("%d", &pos);
    pNew = (node *)malloc(sizeof(node));

    if (pos <= 1)
    {
        printf("Posisi tidak valid. Harus > 1.\n");
        free(pNew);
        getch();
        return;
    }

    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew->data = bil;
    pNew->right = NULL;
    pNew->left = NULL;

    pCur = *head;
    while (pCur != NULL && count < pos - 1)
    {
        pCur = pCur->right;
        count++;
    }

    if (pCur == NULL)
    {
        printf("\nUrutan tidak ditemukan, Data ditambahkan diakhir linked list.");
        if (*head == NULL)
        {
            *head = pNew;
        }
        else
        {
            pCur = *head;
            while (pCur->right != NULL)
            {
                pCur = pCur->right;
            }
            pCur->right = pNew;
            pNew->left = pCur;
        }
    }
    else
    {
        pNew->right = pCur->right;
        pCur->right = pNew;
        pNew->left = pCur;
        if (pNew->right != NULL)
        {
            pNew->right->left = pNew;
        }
        printf("\nData berhasil ditambahkan di urutan ke-%d.\n", pos);
    }
}

//========================================================

void tambahAkhir(node **head)
{
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan sebuah bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL)
    {
        pNew->data = bil;
        pNew->right = NULL;

        if (*head == NULL)
        {
            pNew->left = NULL;
            *head = pNew;
        }
        else
        {

            pCur = *head;
            while (pCur->right != NULL)
            {
                pCur = pCur->right;
            }

            pCur->right = pNew;
            pNew->left = pCur;
        }
    }
    else
    {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================

void tranverse(node *head)
{
    // traverse a linked list
    node *pWalker;

    system("cls");
    pWalker = head;
    while (pWalker != NULL)
    {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->right;
        printf(" -> ");
    }
    printf("NULL");
}

//========================================================

void hapusAwal(node **head)
{
    node *pCur;
    if (*head == NULL)
    {
        printf("List kosong\n");
        getch();
        return;
    }

    system("cls");
    tranverse(*head);

    pCur = *head;
    *head = pCur->right;

    free(pCur);
    printf("\nData berhasil dihapus");
    getch();
}
//========================================================

void hapusData(node **head)
{
    int pos;
    int count = 1;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan urutan data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &pos);

    pCur = *head;
    pPre = NULL;

    if (pos < 1)
    {
        printf("Posisi tidak valid. Harus > 1.\n");
        getch();
        return;
    }

    while (pCur != NULL && count < pos)
    {
        pPre = pCur;
        pCur = pCur->right;
        count++;
    }

    if (pCur == NULL)
    {
        printf("\nData tidak ditemukan");
        getch();
        return;
    }

    if (pCur == *head)
    {
        *head = pCur->right;
        if (*head != NULL)
        {
            (*head)->left = NULL;
        }
    }
    else
    {
        pPre->right = pCur->right;
        if (pCur->right != NULL)
        {
            pCur->right->left = pPre;
        }
    }
    free(pCur);
    printf("\nData berhasil dihapus");
    getch();
}

//========================================================

void hapusAkhir(node **head)
{
    int bil;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);

    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }

    pCur = *head;
    if (pCur->next == NULL)
    {
        free(pCur);
        *head = NULL;
    }
    else
    {
        while (pCur->right != NULL)
        {
            pCur = pCur->right;
        }

        pPre = pCur->left;
        free(pCur);

        if (pPre != NULL)
        {
            pPre->right = NULL;
        }
    }

    printf("\ndata berhasil dihapus");
    getch();
}

//========================================================

void cariData(node **head)
{
    int target, index = 0;
    node *pWalker, *pPre;

    system("cls");
    fflush(stdin);
    printf("masukkan angka yang dicari: ");
    fflush(stdin);
    scanf("%d", &target);

    pWalker = *head;

    while (pWalker != NULL)
    {
        if (pWalker->data == target)
        {
            index = 1;
            break;
        }
        pWalker = pWalker->right;
    }

    if (index)
    {
        printf("Data %d ditemukan dalam linked list.\n", target);
    }
    else
    {
        printf("Data %d tidak ditemukan dalam linked list.\n", target);
    }
    getch();
}

//========================================================

void jumlahData(node **head)
{
    int count = 0;
    node *pWalker;

    system("cls");
    tranverse(*head);

    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }

    pWalker = *head;

    while (pWalker != NULL)
    {
        count++;
        pWalker = pWalker->right;
    }

    printf("\njumlah data dalam list adalah %d\n ", count);
    getch();
}

//========================================================

void totalData(node **head)
{
    int total;
    node *pWalker;

    system("cls");
    tranverse(*head);

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
    }

    pWalker = *head;

    printf("\nData: ");
    while (pWalker != NULL)
    {
        total += pWalker->data;
        printf("%d", pWalker->data);
        if (pWalker->right != NULL)
        {
            printf(" + ");
        }
        pWalker = pWalker->right;
    }

    printf("\nTotal penjumlahan data dalam list adalah %d\n ", total);
    getch();
}