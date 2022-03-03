#include<iostream>
#include<math.h>
#include<string>
using namespace std;
#define max 500
//kêu ngu?i dùng nh?p kích thu?c bàn c? và kh?i t?o tr?ng thái bàn c? ban d?u là 0.
void khoidong(char a[][max],int &m)
{
	cout<<("Moi ban nhap kich thuoc dong va cot\n");
	cin >> m;
	while(m<=5)
	{
		cout<<("Moi ban lai nhap kich thuoc dong va cot\n");
		cin >> m;
	}
	for(int i=0; i < m; i++)
		for(int j=0; j < m; j++)
		{
			a[0][j]=j;
			a[i][0]=i;
			if(i!=0||j!=0)
				a[i][j]='.';

		}
}

//ki?m tra dã d?y quân c? trên bàn c? chua
int isfull(char a[][max],int m)
{
	int dem=0;
	for(int i=0;i< m;i++)
	{
		for(int j=0;j< m;j++)
			if(i!=0&&j!=0)
				if(a[i][j]=='.')
					dem++;
	}
	if(dem==0){
		return 0;
	}
	return 1;
}
//hàm ngu?i choi nh?p quân c?, và ki?m tra tính h?p l? khi ch?n ô c?n dánh
void nhap1(char a[][max],int m,int &i1,int &j1,char s1[])
{
	cout << "\n Moi "<< s1 <<" nhap o can danh " << endl;
	cout <<" Nhap dong: ";
    fflush(stdin);
	cin >> i1;
	cout << "  Nhap cot: ";
	cin >> j1;
	if((i1==100&&j1==100)||(i1==0&&j1==0)){
		return;
	}
	//kiem tra xem o nhap co trung voi o da~ nhap hay chua
	while(i1<=0||j1<=0||a[i1][j1]=='X'||a[i1][j1]=='O'||i1>=m||j1>=m)
	{
		cout << "\n Moi "<< s1 <<" nhap lai o can danh"  << endl;
		cout << "   Nhap dong: ";
	    fflush(stdin);
		cin >> i1;
	    cout <<"   Nhap cot: ";
	    cin >> j1;
		if((i1==100&&j1==100)||(i1==0&&j1==0)){
		    return;
		}
	}

	a[i1][j1]='O';
}


void nhap2(char a[][max],int m,int &i2,int &j2,char s2[])
{
	cout << "\n Moi "<< s2 <<" nhap o can danh:";
    cout <<"   nhap dong: ";
	cin >> i2;
	cout << "   nhap cot:";
	cin >> j2;
	if(i2==100&&j2==100){
		return;
	}
    while(i2<=0||j2<=0||a[i2][j2]=='O'||a[i2][j2]=='X'||i2>=m||j2>=m)
    {
	    cout << "\n Moi "<< s2 <<" lai nhap o can danh";
	    cout << ("   nhap dong: ");
	    cin >> i2;
	    cout << ("   nhap cot:");
	    cin >> j2;
	    if((i2==100&&j2==100)||(i2==0&&j2==0)){
		    return;
	    }
    }
	a[i2][j2]='X';

}
//ki?m tra có win chua
void xet_dong(char a[][max],int m,char s1[],char s2[],int &win)
{
	int demo=0,demx=0;
	for(int i=0;i < m;i++)
	{
		demo=0;
		demx=0;
		for(int j=0;j < m;j++)
		{
			if(a[i][j]=='O')
				demo++;
			else
			{
				if(a[i][j]=='X')
				{
					if(demo >= 4 && a[i][j-(demo+1)]!='X')
					demo = 5;
					else
						demo = 0;
				}
				if(a[i][j] == '.')
					if(demo >= 4)
					    demo = 5;
					else
					    demo = 0;

			}

			if(a[i][j]=='X')
				demx++;
			else
			{	if(a[i][j]=='O')
				{
					if(demx >= 4 && a[i][j-(demx+1)] != 'O')
						demx = 5;
					else
						demx = 0;
				}
				if(a[i][j] == '.')
					if(demx >= 4)
					    demx = 4;
					else
					    demx = 0;
			}

		}
		if(demo >= 4)
		{
			cout << "\nNGUOI CHOI "<< s1 <<" DA THANG" ;
			win = 1;
		}
		if(demx >= 4)
		{
			cout << "\nNGUOI CHOI "<< s2 <<" DA THANG" ;
			win = 1;
		}
	}
}

void xet_cot(char a[][max],int m,char s1[],char s2[],int &win)
{
	int demo = 0, demx = 0;
	for(int j = 0;j< m;j++)
	{
		demo=0;
		demx=0;
		for(int i=0;i< m;i++)

		{
			if(a[i][j]=='O')
				demo++;
			else
			{
				if(a[i][j]=='X')
				{
					if(demo >= 4 &&a[i-(demo+1)][j] != 'X')
						demo = 5;
					else
						demo = 0;
				}
				if(a[i][j] == '.')
					if(demo >= 4)
					demo = 4;
					else
					demo = 0;
			}

			if(a[i][j] == 'X')
				demx++;
			else
			{
				if(a[i][j] == 'O')
				{
					if(demx >= 4 && a[i-demx+1][j] != 'O')
						demx = 5;
					else
						demx = 0;

				}
				if(a[i][j]=='.'){
					if(demx >= 4)
					    demx = 4;
				    else
					    demx=0;
				}
			}
		}
		if(demo >= 4)
		{
			cout << "\nNGUOI CHOI "<< s1 <<" DA THANG" ;
			win=1;
		}
		if(demx >= 4)
		{
			cout << "\nNGUOI CHOI "<< s2 <<" DA THANG" ;
			win=1;
		}

	}
}

void xet_cheo_tren_chinh(char a[][max],int m,char s1[],char s2[],int &win)
{
	int demo = 0, demx = 0;
	int i = 0, k = 0;
	for(int j=1;j< m;j++)
	{
		demo=0;
		demx=0;

		k=j;
		i=0;
		while(k< m)
		{
			if(a[i][k]=='O')
				demo++;
			else
			{
				if(a[i][k]=='X')
				{
					if(demo >= 4 && a[i-demo+1][k-demo+1]!='X')
						demo = 5;
					else
					demo=0;
				}
				if(a[i][k]=='.')
					if(demo >= 4)
					    demo = 4;
					else
					    demo=0;
			}
			if(a[i][k]=='X')
				demx++;
			else
				{
					if(a[i][k]=='O')
					{
						if(demx >= 4 && a[i-demx+1][k-demx+1]!='O')
							demx = 5;
						else
						    demx = 0;
					}
					if(a[i][k]=='.')
						if(demx >= 4)
						demx = 4;
					    else
					    demx=0;
				}
			k++;
			i++;
		}

		if(demo >= 4)
		{
			cout << "\nNGUOI CHOI "<< s1 <<" DA THANG" ;
			win=1;
		}
		if(demx >= 4)
		{
				cout << "\nNGUOI CHOI "<< s2 <<" DA THANG" ;
			win=1;
		}
	}
}

void xet_cheo_duoi_phu(char a[][max],int m,char s1[],char s2[],int &win)
{
	int demo=0,demx=0;
	int j=0,k=0;
	for(int i=1;i< m;i++)
	{
		demo=0;
		demx=0;

		k=i;
		j=m-1;
		while(k< m)
		{

			if(a[k][j]=='O')
			{	demo++;

			}
			else
			{
				if(a[k][j]=='X')
				{
					if(demo>=4&&a[k-demo+1][j+demo+1]!='X')
						demo=4;
					else
					demo=0;
				}
				if(a[k][j]=='.')
					if(demo>=4)
					demo=4;
					else
					demo=0;
			}
			if(a[k][j]=='X')
					demx++;
				else
				{
					if(a[k][j]=='O')
					{
						if(demx>=4&&a[k-demx+1][j+demx+1]=='O')
							demx=5;
						else
						demx=0;
					}
					if(a[k][j]=='.')
						if(demx>=4)
							demx=4;
						else
							demx=0;
				}
					k++;
					j--;

		}

		if(demo>=4)
		{
			cout << "\nNGUOI CHOI "<< s1 <<" DA THANG" ;
			win=1;
		}
		if(demx>=4)
		{
			cout << "\nNGUOI CHOI "<< s2 <<" DA THANG" ;
			win=1;
		}

	}
}

void xet_cheo_duoi_chinh(char a[][max],int m,char s1[],char s2[],int &win)
{
	int demo=0,demx=0;
	int j=0,k=0;
	for(int i=1;i< m;i++)
	{
		demo=0;
		demx=0;

		k=i;
		j=0;
		while(k< m)
		{
			if(a[k][j]=='O')
				demo++;
			else
			{
				if(a[k][j]=='X')
				{	if(demo>=4&&a[k-demo+1][j-demo+1]!='X')
						demo=5;
					else
					demo=0;
				}
				if(a[k][j]=='.')
					if(demo>=4)
					demo=4;
				else
					demo=0;
			}
			if(a[k][j]=='X')
					demx++;
				else
				{
					if(a[k][j]=='O')
						if(demx>=4&&a[k-demx+1][j-demx+1]!='O')
							demx=5;
						else
						demx=0;
					if(a[k][j]=='.')
						if(demx>=4)
							demx=4;
						else
					demx=0;
				}
					k++;
					j++;
		}

		if(demo>=4)
		{
			cout << "\nNGUOI CHOI "<< s1 <<" DA THANG" ;
			win=1;
		}
		if(demx>=4)
		{
				cout << "\nNGUOI CHOI "<< s2 <<" DA THANG" ;
			win=1;
		}
	}
}


void xet_cheo_tren_phu(char a[][max],int m,char s1[],char s2[],int &win)
{
	int demo=0,demx=0;
	int i=0,k=0;
	for(int j=1;j< m;j++)
	{
		demo=0;
		demx=0;

		k=j;
		i=0;
		while(k>0)
		{
			if(a[i][k]=='O')
				demo++;
			else
			{
				if(a[i][k]=='X')
				{
					if(demo>=4&&a[i-demo+1][k+demo+1]!='X')
						demo=5;
					else
					demo=0;
				}
				if(a[i][k]=='.')
					if(demo>=4)
					demo=4;
				else
					demo=0;
			}
			if(a[i][k]=='X')
					demx++;
				else
				{
					if(a[i][k]=='O')
					{
						if(demx>=4&&a[i-demx+1][k+demx+1]!='O')
							demx=5;
						else
						demx=0;
					}
					if(a[i][k]=='.')
						if(demx>=4)
						demx=4;
					    else
					    demx=0;
				}
			k--;
			i++;
		}

		if(demo>=4)
		{
			cout << "\nNGUOI CHOI "<< s1 <<" DA THANG" ;
			win=1;
		}
		if(demx>=4)
		{
			cout << "\nNGUOI CHOI "<< s2 <<" DA THANG" ;
			win=1;
		}
	}
}


void xet_chinh(char a[][max],int m,char s1[],char s2[],int &win)
{
	int demo=0,demx=0;
	for(int i=0;i< m;i++)
	{
		if(a[i][i]=='X')
			demx++;
		else
		{
			if(a[i][i]=='O')
			{
				if(demx >= 4 && a[i-demx+1][i-demx+1]!='O')
					demx=4;
				else
				demx=0;
			}
			if(a[i][i]=='.')
				if(demx>=4)
				demx=4;
			    else
				demx=0;
		}
		if(a[i][i]=='O')
			demo++;
		else
		{
			if(a[i][i]=='X')
			{
				if(demo>=4&&a[i-demo+1][i-demo+1]!='X')
					demo=4;
				else
				demo=0;
			}
			if(a[i][i]=='.')
				if(demo>=4)
				demo=4;
			    else
				demo=0;
		}
	}
	if(demo>=4)
	{
		cout << "\nNGUOI CHOI "<< s1 <<" DA THANG" ;
		win=1;
	}
	if(demx>=4)
	{
		cout << "\nNGUOI CHOI "<< s2 <<" DA THANG" ;
		win=1;
		}

}


void xet_phu(char a[][max],int m,char s1[],char s2[],int &win)
{
	int demo=0,demx=0;
	for(int i=0;i< m;i++)
	{
		demx=0;
		demo=0;
		for(int j=0;j< m;j++)
		{
			if(i+j==m-1)
			{
				if(a[i][j]=='O')
					demo++;
				else
				{
					if(a[i][j]=='X')
					{
						if(demo>=4&&a[i-demo+1][j+demo+1]!='X')
							demo=4;
						else
						demo=0;
					}
					if(a[i][j]=='.')
					if(demo>=4)
						demo=4;
					else
					demo=0;
				}
					if(a[i][j]=='X')
						demx++;
					else
					{
						if(a[i][j]=='O')
						{
							if(demx>=4&&a[i-demx+1][j+demx+1]!='O')
								demx=4;
							else
						    demx=0;
						}
						if(a[i][j]=='.')
							if(demx>=4)
							demx=4;
						    else
					        demx=0;
					}
			}
		}
		if(demo>=4)
		{
			cout << "\nNGUOI CHOI "<< s1 <<" DA THANG" ;
			win=1;
		}
		if(demx>=4)
		{
			cout << "\nNGUOI CHOI "<< s2 <<" DA THANG" ;
			win=1;
		}
	}

}
//xu?t ra bàn c?
void xuat(char a[][max],int m)
{

	cout << "\nban co la:\n";
	for(int i=0;i< m;i++)
	{
		for(int j=0;j< m;j++)
		{
			if(i==0||j==0)
			cout << (int)a[i][j] << "    ";
			else
				cout << a[i][j] << "    ";

		}
		cout <<"\n";
		cout <<"\n";
	}
}
//hàm hu?ng d?n ngu?i choi
void huong_dan()
{
	cout<< "Ban lan luot nhap toa do=(so dong,so cot)\n";
	cout<<"Ban khong duoc nhap len toa do da nhap,neu ban nhap sai se nhap lai\n";
	cout<<"Neu ben nao co >=5 quan co cua minh giong nhau lien tiep thi se thang\n ";
	cout<<"VD:XXXX->Win\n";
	cout<<"Neu ban bi doi phuong chan 2 dau khi ben trong co 4 quan co cua minh nhung van chua Thang\n";
	cout<<"VD:OXXXXO->NO WIN\n";
	cout<<"Neu ban bi doi phuong chan 2 dau khi ben trong co 5 quan co cua minh nhung khong sat thi se Thang\n";
	cout<<"VD OXXXXX O->WIN\n";
	cout<<"Neu ban muon Thoat, exit= so dong=100 va  so cot=100\n";
	cout<<"toa do chet(100,100)\n";
    cout<<"Neu muon choi lai thi nhap: dong:0 va cot 0\n";
    cout<<"(0,0)\n";
	cout<<"Neu ma tat ca cac o bi danh het ma chua co nguoi thang thi 2 ben se hoa\n";
	cout<<"thank you! chuc ban choi vui(^_^)\n";
	cout<<"     2-Bat Dau Choi\n";
	cout<<"     3-Thoat\n";
	cout<<"Ban muon chon:";
}

int main()
{
	int k,n,win=0;
	char s1[20],s2[20],kt;
	char a[max][max];
	int m,i1,j1,i2,j2;
	cout<<"Xin nhap yeu cau\n";
	cout<<"     1-Huong Dan Choi\n";
	cout<<"     2-Bat Dau Choi\n";
	cout<<"     3-Thoat\n";
	cout<<"Ban muon chon:";
	cin >> n;
	do{
	switch(n)
	{


	case 1:
		huong_dan();
		cin >> n;
		break;
	case 2:
		cout <<"\nGAME START\n";
		cout << "Nhap ten cua nguoi choi thu 1: ";
		cin >> s1;
		printf("Nhap ten cua nguoi choi thu 2: ");
		cin >> s2;
		khoidong(a,m);
		system("cls");
		xuat(a,m);
		do
		{

		k=isfull(a,m);
		cout<<" K : " <<k<<endl;
		if(k==1)
		{
			nhap1(a,m,i1,j1,s1);
		}
		system("cls");
		xuat(a,m);
		xet_dong(a,m,s1,s2,win);
		xet_cot(a,m,s1,s2,win);
		xet_cheo_tren_chinh(a,m,s1,s2,win);
		xet_cheo_tren_phu(a,m,s1,s2,win);
		xet_cheo_duoi_phu(a,m,s1,s2,win);
		xet_cheo_duoi_chinh(a,m,s1,s2,win);
		xet_chinh(a,m,s1,s2,win);
		xet_phu(a,m,s1,s2,win);
		if(win==1||k==0||(i1==100&&j1==100)||(i2==100&&j2==100)||(i1==0&&j1==0)||(i2==0&&j2==0))
		{
			cout << " ban co muon choi lai khong? Y/N \n";
			cin >> kt;
			if((i1==0&&j1==0)||(i2==0&&j2==0)||kt=='Y'||kt=='y'||k==0)
			{
				if(k==0)
				cout << " "<< s1 <<" HOA "<< s2 <<"\n";
				win=0;
				break;
			}
			else
			{
			return 0;
			}
		}
		k=isfull(a,m);
		if(k==1)
		{
			nhap2(a,m,i2,j2,s2);

		}
		system("cls");
		xuat(a,m);
		xet_dong(a,m,s1,s2,win);
		xet_cot(a,m,s1,s2,win);
		xet_cheo_tren_chinh(a,m,s1,s2,win);
		xet_cheo_tren_phu(a,m,s1,s2,win);
		xet_cheo_duoi_phu(a,m,s1,s2,win);
		xet_cheo_duoi_chinh(a,m,s1,s2,win);
		xet_chinh(a,m,s1,s2,win);
		xet_phu(a,m,s1,s2,win);
		if(win==1||k==0||(i1==100&&j1==100)||(i2==100&&j2==100)||(i1==0&&j1==0)||(i2==0&&j2==0))
		{
			cout << "ban co muon choi lai khong? Y/n \n";
			cin >> kt;
			if((i1==0&&j1==0)||(i2==0&&j2==0)||kt=='Y'||kt=='y'||k==0)
			{
				if(k==0)
				cout << ""<< s1 <<" HOA "<< s2 <<"\n";
				win=0;
				break;
			}

			else
			{

				return 0;
			}
		}

		}
		while(k==1&&win==0);
		break;
	case 3:
		break;
	default:
			cout << "Ban da chon sai\n Moi ban nhap lai:";
			cin >> n;
	}
	}while(n!=3);

}
