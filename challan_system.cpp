#include <bits/stdc++.h>
using namespace std;

long getch(string s);
int convertc(char ch);

class challan
{
	public:
	string ofno;
	string vehno;
	string ofnam;
	float price;
	challan* nxt;
	challan* pre;
	bool paid;
	
	challan()
	{
		ofno = "";
		price = 0;
		vehno = "";
		ofnam = "";
		nxt = nullptr;
		pre = nullptr;
		paid = 0;
	}
	challan(string no,string ona,float y,string vno,bool ck)
	{
		ofno = no;
		ofnam = ona;
		vehno = vno;
		price = y;
		nxt = nullptr;
		pre = nullptr;
		paid = ck;
	}
	void outc()
	{
		cout<<"\nchallan no: "<<ofno;
		cout<<"\noffense name : "<<ofnam;
		cout<<"\nCar no : "<<vehno;
		cout<<"\nPrice : "<<price;
		if(paid)
		{
			cout<<"\nPAID";
		}
		else
		{
			cout<<"\nNOT PAID";
		}
	}
};
class record
{
	public:
	string ch;
	string no;
	string carnam;
	string name;
	int whler;
	string fuel;
	string eno;
	string cno;
	challan* chl;
	
	record *left,*right;
	
		record()
		{
			left = nullptr;
			right = nullptr;
			name = "";
			chl = nullptr;
		}
		record(string cd,string n)
		{
			ch = cd;
			no = n;
			left = nullptr;
			right = nullptr;
			chl = nullptr;
		}
		record(string crno,string cnm,string onm,int whe,string fl,string en,string cn)
		{
			no=crno;
			carnam = cnm;
			name = onm;
			whler = whe;
			fuel = fl;
			eno = en;
			cno = cn;
			left = nullptr;
			right = nullptr;
			chl = nullptr;
		}
		void entr()
		{
			fflush(stdin);
			cout<<"Enter car name\n";
			getline(cin,carnam);
			fflush(stdin);
			cout<<"Enter owner name:\n";
			getline(cin,name);
			fflush(stdin);
			cout<<"Enter type of car (2/4) wheeler\n";
			cin>>whler;
			fflush(stdin);
			cout<<"Enter fuel type\n";
			getline(cin,fuel);
			fflush(stdin);
			cout<<"Enter engine no \n";
			getline(cin,eno);
			fflush(stdin);
			cout<<"Enter chasis no\n";
			getline(cin,cno);
			cout<<endl;
		}
		void out()
		{
			cout<<"\ncar no: "<<no;
			cout<<"\nCar name: "<<carnam;
			cout<<"\nOwner name: "<<name;
			cout<<"\ntype : "<<whler;
			cout<<"\nFuel type : "<<fuel;
			cout<<"\nEngine no: "<<eno;
			cout<<"\nchasis no: "<<cno;  
		}
};
class dis {
public:
    string ch;
    record *next;
    dis *left, *right;
    dis()
    {
        left = nullptr;
        right = nullptr;
        next = nullptr;
	}
    dis(string new_ch) {
        ch = new_ch;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
class state {
public:
    string ch;
    dis *next;
    state *left, *right;
    state()
    {
        left = nullptr;
        right = nullptr;
        next = nullptr;
	}
    state(string newch) {
        ch = newch;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};
void insertdis(dis* &b,string np,record* rz);
void insertrc(record* &b,string np,record* rz);

class dl
{
	public:
	string ch;
	string ownm;
	string fnam;
	string adress;

	challan* chn;
	
	dl *left,*right;
	
		dl()
		{
			left = nullptr;
			right = nullptr;
			ownm = "";
			ch = "";
			fnam = "";
			chn = nullptr;
		}
		dl(string n)
		{
			ch = n;
			left = nullptr;
			right = nullptr;
			chn = nullptr;
		}
		dl(string n,string ow,string fn,string ad)
		{
			ch=n;
			ownm = ow;
			fnam = fn;
			adress = ad;
			left = nullptr;
			right = nullptr;
			chn = nullptr;
		}
		void entrdl()
		{
			fflush(stdin);
			cout<<"Enter dl no:\n";
			getline(cin,ch);
			fflush(stdin);
			cout<<"Enter name\n";
			getline(cin,ownm);
			fflush(stdin);
			cout<<"Enter Father name:\n";
			getline(cin,fnam);
			fflush(stdin);
			cout<<"Enter Address\n";
			getline(cin,adress);
			cout<<endl;
		}
		void out()
		{
			cout<<"\nlicense no: "<<ch;
			cout<<"\nOwner name: "<<ownm;
			cout<<"\nFather name: "<<fnam;
			cout<<"\nAddress: "<<adress;
			cout<<endl;
		}
};
dl* searchdl(dl *x,string sr)
{
	dl* rt = x;
	long z = getch(sr);
	while(rt!=nullptr)
	{
		if(getch(rt->ch) > z)
		{
			rt = rt->left;
		}
		else if(getch(rt->ch) < z)
		{
			rt = rt->right;
		}
		else 
		{
			cout<<"found\n";
			return rt;
		}
	}
	cout<<"No such record found\n";
	return nullptr;
}
void insertdl(dl *&x,dl *nxt)
{
	transform(nxt->ch.begin(), nxt->ch.end(), nxt->ch.begin(), ::toupper);
	dl* ck = searchdl(x,nxt->ch);
	if(ck!=nullptr)
	{
		cout<<"Already present...\n";
		return;
	}
	long z = getch(nxt->ch);
	dl *r = x;
	dl *p = r;
	
		if(r==nullptr)
		{
			x = nxt;
			return;
		}
		while(r!=nullptr)
		{
			p=r;
			if(getch(r->ch) > z)
			{
				
				r=r->left;
			}
			else
			{
				r=r->right;
			}	
			
		}
		if(getch(p->ch) > z)
		{
			p->left = nxt;
		}
		else
		{
			p->right = nxt;
		}
		cout<<"\nrecord added\n";
}
template<typename T>
void printww(T *c)
{
	T* z = c;
	while(z!=nullptr)
	{
		cout<<z->ch;
		z = z->left;
	}
	z= c->right;
	while(z!=nullptr)
	{
		cout<<z->ch;
		z = z->right;
	}
}
template<typename T>
T* searchnde(T* b,string sa)
{
	long z = getch(sa);
	T* rt = b;
	while(rt!=nullptr)
	{
		if(getch(rt->ch) > z)
		{
			rt = rt->left;
		}
		else if(getch(rt->ch) < z)
		{
			rt = rt->right;
		}
		else
		{
			return rt;
		}
	}
}
void insert(state* &b,string np,record* rz)
{
	transform(np.begin(), np.end(), np.begin(), ::toupper);
	string a;
	a.push_back(np[0]);
	a.push_back(np[1]);
	state* c = searchnde<state>(b,a);
	
	if(c!=nullptr)
	{
		insertdis(c->next,np,rz);
		return;
	}
		long z = getch(a);
		state* nxt = new state(a);
		state *r = b;
		state *p = r;
	
		if(r==nullptr)
		{
			b = nxt;
			insertdis(nxt->next,np,rz);
			return;
		}
		while(r!=nullptr)
		{
			p=r;
			if(getch(r->ch) > z)
			{
				r=r->left;
			}
			else
			{
				r=r->right;
			}	
		}
		if(getch(p->ch) > z)
		{
			p->left = nxt;
		}
		else
		{
			p->right = nxt;
		}
		insertdis(nxt->next,np,rz);
}
void insertdis(dis* &b,string np,record* rz)
{
	string a;
	a.push_back(np[2]);
	a.push_back(np[3]);
	 
	dis* c = searchnde<dis>(b,a);
	
	if(c!=nullptr)
	{
		insertrc(c->next,np,rz);	
		//printww<record>(c->next);
		return;
	}
		long z = getch(a);
		dis* nxt = new dis(a);
		dis *r = b;
		dis *p = r;
		if(r==nullptr)
		{
			b = nxt;
			insertrc(nxt->next,np,rz);
			return;
		}
		while(r!=nullptr)
		{
			p=r;
			if(getch(r->ch) >z)
			{
				r=r->left;
			}
			else
			{
				r=r->right;
			}	
		}
		if(getch(p->ch) > z)
		{
			p->left = nxt;
		}
		else
		{
			p->right = nxt;
		}
		insertrc(nxt->next,np,rz);
}


void insertrc(record* &b,string np,record* nxt)
{
   	string a;
	for(int i=4;i<np.size();++i)
	{
		a.push_back(np[i]);
	}
	record* c = searchnde<record>(b,a);
	if(c!=nullptr)
	{
		cout<<"Already registered : "<<a<<endl;
		c->out();
	}
		nxt->ch = a;
		nxt->no = np;
		long z = getch(a);
		//record* nxt = new record(a,np);
		record *r = b;
		record *p = r;
		if(r==nullptr)
		{
			b = nxt;
			cout<<"inserted";
			return;
		}
		long k;
		while(r!=nullptr)
		{	
			k= getch(r->ch);
			p=r;
			if(k > z)
			{
				r=r->left;
			}
			else
			{
				r=r->right;
			}	
		}
		if(getch(p->ch) > z)
		{
			p->left = nxt;
		}
		else
		{
			p->right = nxt;
		}
		cout<<"inserted";
}
template<typename T>
void showrcd(T* b)
{
	T* rt = b;
	cout<<endl;
	if(rt==nullptr)
	return;
	
	showrcd(b->left);
	rt->out();
	showrcd(b->right);
}

void showd(dis* b)
{
	dis* rt = b;
	
	while(rt==nullptr)
	return;
	
	showd(b->left);
	showrcd<record>(b->next);
	showd(b->right);
}
void shownos(state* b)
{
	state* rt = b;
	
	while(rt==nullptr)
	return;
	
	shownos(b->left);
	showd(b->next);
	shownos(b->right);
}


record *searchc(state* &b,string np)
{
	transform(np.begin(), np.end(), np.begin(), ::toupper);
	string a;
	a.push_back(np[0]);
	a.push_back(np[1]);
	state* p = searchnde<state>(b,a);
	if(p==nullptr)
	{
		cout<<"\nNot found\n";
		return nullptr;
	}
	a.clear();
	a.push_back(np[2]);
	a.push_back(np[3]);
	dis* q = searchnde<dis>(p->next,a);
	if(q==nullptr)
	{
		cout<<"\nNot found\n";
		return nullptr;
	}
	a.clear();
	for(int i=4;i<np.size();++i)
	{
		a.push_back(np[i]);
	}
	
	record* r = searchnde<record>(q->next,a);
	if(r==nullptr)
	{
		cout<<"\nNot found\n";
		return nullptr;
	}
	else 
	{
		return r;
	}
}
template<typename T>
T* minv(T* root)
{
	T *rt = root;
	while(rt->left!=nullptr && rt!=nullptr)
	{
		rt = rt->left;
	}
	return rt;
}
template<typename T>
T* delteno(T* root,string st)
{
	long ky = getch(st);
    if (root == nullptr)
        return root;
 	
    if (ky < getch(root->ch))
        root->left = delteno<T>(root->left, st);
        
    else if (ky > getch(root->ch))
        root->right = delteno<T>(root->right, st);
    else {
        if (root->left==nullptr and root->right==nullptr)
        	return nullptr;
        else if (root->left == nullptr) {
            root = root->right;
            return root;
        }
        else if (root->right == nullptr) {
            root = root->left;
            return root;
        }
        T* temp = minv<T>(root->right);
        root->ch = temp->ch;
 
        root->right = delteno(root->right, temp->ch);
    }
    return root;
}
void deletee12(state* &b,string np)
{
	
	transform(np.begin(), np.end(), np.begin(), ::toupper);
	string a;
	a.push_back(np[0]);
	a.push_back(np[1]);
	state* p = searchnde<state>(b,a);
	a.clear();
	a.push_back(np[2]);
	a.push_back(np[3]);
	if(p==nullptr)
	{
		cout<<"no such record";
		return;
	}
	dis* q = searchnde<dis>(p->next,a);
	a.clear();
	if(q==nullptr)
	{
		cout<<"no such record";
		return;
	}
	for(int i=4;i<np.size();++i)
	{
		a.push_back(np[i]);
	}
	q->next = delteno<record>(q->next,a);
	cout<<"Record deleted succesfully";
}
void issuechalan(state *b,string str,string cno,string cn,float ft,bool ck)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	record *rc = searchc(b,str);
	if(rc==nullptr)
	{
		cout<<"No such record";
	}	
	else
	{
		rc->out();
	}
	challan *cl = new challan(cno,cn,ft,str,ck);
	
	if(rc!=nullptr)
	{
		if(rc->chl != nullptr)
		{
			rc->chl->pre = cl;
			cl->nxt = rc->chl;
			rc->chl = cl;
		}
		else
		{
			rc->chl = cl;
		}
	}
}
void issuechalandl(dl *b,string str,string cno,string cn,float ft,bool ck)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	dl *rc = searchdl(b,str);
	if(rc==nullptr)
	{
		cout<<"No such record";
	}	
	else
	{
		rc->out();
	}
	challan *cl = new challan(cno,cn,ft,str,ck);
	
	if(rc!=nullptr)
	{
		if(rc->chn != nullptr)
		{
			rc->chn->pre = cl;
			cl->nxt = rc->chn;
			rc->chn = cl;
		}
		else
		{
			rc->chn = cl;
		}
	}
}
challan* searchchaln(challan* ch,string cno)
{
	challan* rt = ch;
	while(rt!=nullptr)
	{
		if(rt->ofno == cno)
		{
			return rt;
		}
		rt = rt->nxt;
	}
}
void paychalln(state *b,string str,string cno)
{
	record *rc = searchc(b,str);
	if(rc==nullptr)
	{
		cout<<"no such record\n";
		return;
	}
	else
	{
		rc->out();		
	} 

	challan* ch = searchchaln(rc->chl,cno);
	
	if(ch!=nullptr)
	{
		if(ch->paid)
		{
			cout<<"\nAlready paid\n";
			return;
		}
		ch->paid = 1;
		
	}
	else
	{
		cout<<"no such challan found..\n";
		return;
	}
		cout<<"\nPAID";
}

void showchallan(state *b,string str)
{
	record *rc = searchc(b,str);
	challan *cl = rc->chl;
	while(cl!=nullptr)
	{
		cl->outc();
		cl = cl->nxt;
	}
	
}
void showchallandl(dl *b,string str)
{
	dl *rc = searchdl(b,str);
	challan *cl = rc->chn;
	while(cl!=nullptr)
	{
		cl->outc();
		cl = cl->nxt;
	}
}
void paychallndl(dl *b,string str,string cno)
{
	dl *rc = searchdl(b,str);
	if(rc==nullptr)
	{
		cout<<"no such record\n";
		return;
	}
	else
	{
		rc->out();		
	} 

	challan* ch = searchchaln(rc->chn,cno);
	if(ch!=nullptr)
	{
		ch->paid = 1;
	}
	else
	{
		cout<<"no such challan found on above dl..\n";
		return;
	}
	cout<<"PAID";
}
void generatecardata(state *&a)
{
	ifstream inFile;
    inFile.open("st.txt");
    if (!inFile) {
        cerr << "Unable to open file student.txt";
        exit(1);   
    }

    // Variables that will collect data
    string temp;
 	string carid;
 	string carnm;
 	int whel;
	string ownm;
    string fuel;
    string en;
    string cn;
    int nof;
	string ofno; 
	string ofnm;
	float prc;
	bool pd;
	
    while (getline(inFile, carid)) {
        // converting shelve_str to int
		getline(inFile, carnm);
        getline(inFile, ownm);
        
        getline(inFile, temp);
        whel = stoi(temp);
        getline(inFile, fuel);
        getline(inFile, en);
        getline(inFile, cn);
        
        record* rc = new record(carid,carnm,ownm,whel,fuel,en,cn);
		insert(a,carid,rc);
        getline(inFile, temp);
        int n = stoi(temp);
        for(int i=0;i<n;++i)
        {
        	getline(inFile, ofno);
            getline(inFile, ofnm);
            getline(inFile, temp);
        	prc = stod(temp);
        	getline(inFile, temp);
        	pd = stoi(temp);
            issuechalan(a,carid,ofno,ofnm,prc,pd);
		}
    }
    inFile.close();
}

void generatedldata(dl *&a)
{
	ifstream inFile;
    inFile.open("dl.txt");
    if (!inFile) {
        cerr << "Unable to open file student.txt";
        exit(1);   
    }

    // Variables that will collect data
    string temp;
 	string dlno;
 	string own;
	string fn;
    string adrs;
    int nof;
	string ofno; 
	string ofnm;
	float prc;
	bool pd;
	
    while (getline(inFile, dlno)) {
        // converting shelve_str to int
		getline(inFile, own);
        getline(inFile, fn);
        
        getline(inFile, adrs);
        
        dl* rc = new dl(dlno,own,fn,adrs);
		insertdl(a,rc);
        getline(inFile, temp);
        int n = stoi(temp);
        for(int i=0;i<n;++i)
        {
        	getline(inFile, ofno);
            getline(inFile, ofnm);
            getline(inFile, temp);
        	prc = stod(temp);
        	getline(inFile, temp);
        	pd = stoi(temp);
            issuechalandl(a,dlno,ofno,ofnm,prc,pd);
		}
    }
    inFile.close();
}
void addnw(state* a)
{
	record *rd = new record();
	string s;
	fflush(stdin);
	cout<<"Enter the car no\n";
	getline(cin,s);
	rd->entr();
	insert(a,s,rd);
}
void lock(){
string access;
    cout << "\t\t\t\tWELCOME TO THE CAR INFO \n\n" << "\t\tTo Exit Press (X)\n" << "\t\tEnter Access Code \n\t\t(default password : root): \n\n\t\t";
    CODE:
    cin >> access;
    cout << "\n";

    if (access=="root"){
        cout << "\t\tAccess Granted" << endl;
    }
    else if (access=="x" || access=="X")
        exit(0);
    else {
        cout << "!! Invalid Access Code !!" << endl;
        goto CODE;
    }
    system("cls");
}
void choice(state* &a,dl* &d)
{
	system("cls");
	int ch;
	string s;
	cout<<"\n\t\t\t******* Index ********\n";
	cout<<"\n\t\t\t1.Add new car\n";
	cout<<"\t\t\t2.Delete a record of car\n";
	cout<<"\t\t\t3.Show all record of cars\n";
	cout<<"\t\t\t4.issue challan on car no\n";
	cout<<"\t\t\t5.Pay challan on car\n";
	cout<<"\t\t\t6.Show challans on car\n";
	cout<<"\t\t\t7.Insert a dl\n";
	cout<<"\t\t\t8.Search a dl\n";
	cout<<"\t\t\t9.Issue challan on dl\n";
	cout<<"\t\t\t10.Delete a dl\n";
	cout<<"\t\t\t11.Show all dl\n";
	cout<<"\t\t\t12.Pay challan on dl\n";
	cout<<"\t\t\t13.Show challan on dl\n";
	cout<<"\t\t\t0. To exit\n";
	cout<<"\t\t\tEnter your choice\n\t\t\t";
	
	cin>>ch;
	switch(ch){
		case 1:{
			lock();
			addnw(a);
			break;
		}
		case 2:{
			lock();
			fflush(stdin);
			cout<<"Enter no to delete\n";
			getline(cin,s);
			deletee12(a,s);
			break;
		}
		case 3:{
			shownos(a);
			break;
		}
		case 4:{
			lock();
			string vn,cn,cno;
			float pr;
			char ct;
			fflush(stdin);
			cout<<"Enter vehicle no\n";
			getline(cin,vn);
			fflush(stdin);
			cout<<"Enter challan no\n";
			getline(cin,cno);
			fflush(stdin);
			cout<<"Enter challan name\n";
			getline(cin,cn);
			fflush(stdin);
			cout<<"Enter challan price\n";
			cin>>pr;
			cout<<"is it paid?(y/n)\n";
			cin>>ct;
			if(ct=='y' || ct=='Y')
			{
				issuechalan(a,vn,cno,cn,pr,1);
			}
			else if(ct=='n' || ct=='N')
			{
				issuechalan(a,vn,cno,cn,pr,0);
			}
			cout<<"\n\nIssued";
			break;
		}
		case 5:{
			string vn,cno;
			fflush(stdin);
			cout<<"Enter vehicle no\n";
			getline(cin,vn);
			fflush(stdin);
			cout<<"Enter challan no\n";
			getline(cin,cno);
			paychalln(a,vn,cno);
			break;
		}
		case 6:{
			string vn;
			fflush(stdin);
			cout<<"Enter vehicle no\n";
			getline(cin,vn);
			showchallan(a,vn);
			break;
		}
		case 7:{
			lock();
			dl* dtemp = new dl();
			dtemp->entrdl();
			insertdl(d,dtemp); 
			break;
		}
		case 8:{
			string ds;
			fflush(stdin);
			cout<<"Enter the dl no\n";
			getline(cin,ds);
			dl* dt = searchdl(d,ds);
			if(dt!=nullptr)
			{
				dt->out();
			}
			cout<<endl;
			break;
		}
		case 9:{
			lock();
			string ln,cn,cno;
			float pr;
			char ct;
			fflush(stdin);
			cout<<"Enter dl no\n";
			getline(cin,ln);
			fflush(stdin);
			cout<<"Enter challan no\n";
			getline(cin,cno);
			fflush(stdin);
			cout<<"Enter challan name\n";
			getline(cin,cn);
			cout<<"Enter challan price\n";
			cin>>pr;
			cout<<"is it paid?(y/n)\n";
			cin>>ct;
			if(ct=='y' || ct=='Y')
			{
				issuechalandl(d,ln,cno,cn,pr,1);
			}
			else if(ct=='n' || ct=='N')
			{
				issuechalandl(d,ln,cno,cn,pr,0);
			}
			break;
		}
		case 10:{
			lock();
			string ds;
			fflush(stdin);
			cout<<"Enter the dl no to delete\n";
			getline(cin,ds);
			d = delteno<dl>(d,ds);
			cout<<"\nDone\n";
			break;
		}
		case 11:{
			showrcd<dl>(d);
			break;
		}
		case 12:{
			string vn,cno;
			fflush(stdin);
			cout<<"Enter dl no\n";
			getline(cin,vn);
			fflush(stdin);
			cout<<"Enter challan no\n";
			getline(cin,cno);
			paychallndl(d,vn,cno);
			break;
		}
		case 13:{
			string vn;
			fflush(stdin);
			cout<<"Enter dl no\n";
			getline(cin,vn);
			showchallandl(d,vn);
			break;
		}
		case 0:{
			return;
		}
		
}
		char cd;
		cout<<"\n\nPress y to get back to index....\n";
		cin>>cd;
		
		if(cd=='y' || cd=='Y')
		{
			choice(a,d);
		}
		else if(cd=='n' || cd=='N')
		{
			return;
		}
		else
		{
			cout<<"\ninvalid choice\n";
		}
}
void welcome()
{
	cout<<"\n\n\n";
	cout<<"\t\t\t*            *  *****  *     *****  *****  *    *  *****   \n";
	cout<<"\t\t\t *          *   *      *     *      *   *  **  **  *       \n";
	cout<<"\t\t\t  *   **   *    ****   *     *      *   *  * ** *  ****    \n";
	cout<<"\t\t\t   * *  * *     *      *     *      *   *  *    *  *       \n";
	cout<<"\t\t\t    *    *      *****  ***** *****  *****  *    *  *****   \n";
	
	cout<<"\n\n";
	
	cout<<"\t\t\t\t\t *******  ******\n";
	cout<<"\t\t\t\t\t    *     *    *\n";
	cout<<"\t\t\t\t\t    *     *    *\n";
	cout<<"\t\t\t\t\t    *     *    *\n";
	cout<<"\t\t\t\t\t    *     ******\n";
	
	cout<<"\n\n";
	
	cout<<"\t\t\t*****  *   *  *****  *      *     ***** *   *    \n";
	cout<<"\t\t\t*      *   *  *   *  *      *     *   * **  *    \n";
	cout<<"\t\t\t*      *****  *****  *      *     ***** * * *    \n";
	cout<<"\t\t\t*      *   *  *   *  *      *     *   * *  **    \n";
	cout<<"\t\t\t*****  *   *  *   *  *****  ***** *   * *   *    \n";	
	
	
	cout<<"\n\n";
	cout<<"Press Enter\n";
	cin.ignore();
	
}
void by()
{
	system("cls");
	cout<<"\n\n\n\t\t\t\t\tPROJECT DS\n";
	cout<<"\n\n\n\t\t\t\t\t\tSubmitted by:";
	cout<<"\n\t\t\t\t\t\tAman Deep Gupta   (9919103179)";
	cout<<"\n\t\t\t\t\t\tSaransh Pateriya  (9919103187)";
	cout<<"\n\t\t\t\t\t\tAditi 	          (9919103200)";
	cout<<"\n\t\t\t\t\t\tKunal Mittal 	  (9919103201)";
	
	cout<<"\n\n\t\t\t\tPress Enter To continue";

	cin.ignore();
	system("cls");
}
int main()
{
	welcome();
	by();
	state *a = nullptr;
	dl* d = nullptr;
	generatedldata(d);
	generatecardata(a);
	choice(a,d);
}
int convertc(char ch)
{
	ch=toupper(ch);
	int i=(int)ch;
	i = i-48;
	if(i<10)
	{
		return i;
	}
	else return i-16;
}

long getch(string s)
{
	queue<int> chq;
	int cs=0,ch=0,n=s.size();
	for(int i=0;i<n;++i)
	{
		
		if(s[i]==' ')
		{
			chq.push(cs);
			cs=0;
		}
		else
		{
			
			cs+=convertc(s[i]);
			
		}
	}
	chq.push(cs);
    cs=0; 
    stringstream string_stream;
    while (!chq.empty()) {
        string_stream << chq.front();
        chq.pop();
    }
    
    string combining_values = string_stream.str();
    istringstream integer_string_stream(combining_values);
    integer_string_stream >> ch;
    return ch;
}
