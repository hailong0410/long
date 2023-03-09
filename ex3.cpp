#include<iostream>
using namespace std;

// Bài toán: Nhập danh sách liên kết đơn các số nguyên. Tìm giá trị lớn nhất trong danh sách

// ============== KHAI BÁO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN ==============
// khai báo cấu trúc 1 cái node
struct node
{
	int data; // dữ liệu chứa trong 1 cái node 
	struct node *pNext; // con trỏ dùng để liên kết giữa các cái node với nhau
};
typedef struct node NODE; // thay thế struct node thành NODE

// khai báo cấu trúc của danh sách liên kết đơn
struct list
{
	NODE *pHead; // node quản lí đầu danh sách
	NODE *pTail; // node quản lí cuối danh sách
};
typedef struct list LIST; // thay thế struct list thành LIST

// ============== KHỞI TẠO CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN ==============
void KhoiTao(LIST &l)
{
	// cho 2 node trỏ đến NULL - vì danh sách liên kết đơn chưa có phần tử
	l.pHead = NULL;
	l.pTail = NULL;
}

// hàm khởi tạo 1 cái node
NODE *KhoiTaoNODE(int x)
{
	NODE *p = new NODE; // cấp phát vùng nhớ cho NODE p
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x; // truyền giá trị x vào cho data
	p->pNext = NULL; // đầu tiên khai báo node thì node đó chưa có liên kết đến node nào hết ==> con trỏ của nó sẽ trỏ đến NULL
	return p; // trả về NODE p vừa khởi tạo
}

// hàm thêm node p vào đầu danh sách liên kết
void ThemVaoDau(LIST &l, NODE *p)
{
	/// danh sách đang rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và là p
	}
	else
	{
		p->pNext = l.pHead; // cho con trỏ của node cần thêm là node p liên kết đến node đầu - pHead
		l.pHead = p; // cập nhật lại pHead chính là node p
	}
}

// hàm thêm node p vào cuối danh sách liên kết
void ThemVaoCuoi(LIST &l, NODE *p)
{
	/// danh sách đang rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và là p
	}
	else
	{
		l.pTail->pNext = p; // cho con trỏ của pTail liên kết với node p
		l.pTail = p; // cập nhật lại p là node pTail
	}
}

// hàm xuất danh sách liên kết đơn
void XuatDanhSach(LIST l)
{
	// for(int i = 0; i < n; i++)
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << k->data << " ";
	}
}

// hàm tìm giá trị lớn nhất trong danh sách
int TimMax(LIST l)
{
	int max = l.pHead->data; // giả sử node đầu là node lớn nhất
	// bắt đầu duyệt từ node thứ 2 để kiểm tra
	for (NODE *k = l.pHead->pNext; k != NULL; k = k ->pNext)
	{
		if (max < k->data)
		{
			max = k->data; // cập nhật lại giá trị max
		}
	}
	return max;
}

int main()
{
	LIST l;
	KhoiTao(l); // khởi tạo danh sách liên kết đơn


	int n;
	cout << "\nNhap so luong node can them: ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "\nNhap gia tri so nguyen: ";
		cin >> x;
		NODE *p = KhoiTaoNODE(x); // khởi tạo 1 cái node số nguyên
		ThemVaoCuoi(l, p); // thêm node p vào đầu danh sách liên kết đơn 
	}
	cout << "\n\n\t DANH SACH LIEN KET DON\n";
	XuatDanhSach(l);

	cout << "\n\n\t GIA TRI LON NHAT: " << TimMax(l);
	system("pause");
	return 0;
}