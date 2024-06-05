#include <iostream>
#include <fstream> 
using namespace std;
class phanso
{
	private:
		float tso,mso;
	public:
		phanso();
		phanso(float a,float b);
		phanso operator *(phanso t);
		float operator !(); 
	friend istream& operator>> (istream&x ,phanso &y);
	friend ostream& operator << (ostream&z  ,phanso t); 
 }; 
phanso::phanso()
 {
 	tso=1;
	mso=2; 
  } 
phanso::phanso(float a,float b)
{
	tso=a;
	mso=b; 
}
istream& operator>>(istream&x ,phanso &y)
{
	cout<<"\n nhap tu so:";		x>>y.tso ;
	cout<<"\n nhap mau so:";	x>>y.mso;
	return x; 
  }  
ostream& operator<<(ostream&z  ,phanso t)
{
	z<<"phan so :"<<t.tso<<"/" <<t.mso<<endl; 
		return z; 
 } 
phanso phanso :: operator *(phanso t)
{
	phanso  y;
	y.tso=tso*t.tso;
	y.mso=mso*t.mso; 
	return y; 
 } 
float phanso ::operator!()
{
	return tso/mso; 
 } 
main()
{
	ofstream file("PHANSO.TXT");
	phanso p1; 
	phanso p2,p3;
	cout<<"\n nhap phan so thu nhat:"<<endl;
	cin>>p2; 
	cout<<"\n nhap phan so thu hai:"<<endl;
	cin>>p3; 
	phanso p4; 
	p4=p2*p3; 
	//cout<<"\n tich cua 2 phan so la:"<<!p4<<endl;
	file<<"ket qua tich 2 phan so la:"<<!p4<<endl; 
	file.close() ;
	cout<<"ket qua da in vao file PHANSO.TXT"; 
			return 0; 
			
 } 

 


