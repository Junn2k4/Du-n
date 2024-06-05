#include<bits/stdc++.h>
using namespace std;
// phuong thuc toan tu- ham toan tu
 // cai dat- cu phap
// su dung
// vi du: cai ptt cho lop phanso
// 1/2+3/4=?
// phuong thuc toan cong 2 phanso
// c1:hai ngoi( 2 doi so) tro thanh 1 doi so
//c2 : hai ngoi ( 2 doi so)
class phanso
{
	private:
		int ts;
		int ms;
	public:
		phanso()
		{
			ts=0;
			ms=1;
		}
		
		phanso(int t, int m)
		{
			ts=t;
			ms=m;
		}
	
		void xuat()
		{
			cout<<ts<<"/"<<ms;			
		}
//		phanso operator +( phanso y)
//		{
//			phanso kq;
//			kq.ts=ts*y.ms+y.ts*ms;
//			kq.ms=ms*y.ms;
//			kq.ts=this->ts*y.ms+y.tsthis->ms;
//			kq.ms=this->ms*y.ms;
	//	return kq;
	//	}
	friend	phanso operator +(phanso x, phanso y)
		{
			phanso kq;
			kq.ts=x.ts * y.ms+y.ts*x.ms;
			kq.ms=x.ms*y.ms;
		return kq;
		}
};
main()
{
	phanso a,t1(4,3),t2(4,4);
	cout<<"\n phan so thu 1: ";
	t1.xuat();
	cout<<"\n phan so thu 2: ";
	t2.xuat();
	cout<<"\n phuong thuc toan tu cong 2 phan so: ";
	a=t1+t2;
	a.xuat();
	
	
	
}
