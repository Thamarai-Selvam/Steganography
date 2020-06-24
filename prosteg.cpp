
#include<string.h>
#include<cmath>
#include <cstdio>
#include <cstdlib>
#include<conio.h>
#include "bitmap_image.hpp"
#include<iostream>
using namespace std;



class stegno
{
	public:
	bitmap_image  image;
	
	
	void detext()
	{
	
		
	
	
	int n;
	
	int x;
	
	int remainder;
	int l=1;
	int k;
	k=0;
	long binary=0;
	
	
	

	int count=0;
	
	
	long bina=binary;
	int bt[8];
	
	
		
	int v=7,v1=7;

	
	int rc[8];
	int gc[8];
	int bc[8];
	long b1=0;
	long b2=0;
	long b3=0;
	int q=0;

	
		
		
		int r=0,g=0,b=0;
			int height=image.height();
			int width=image.width();
		
		for(std::size_t i=0;i<height;i++)
		{
		
		for(std::size_t j=0;j<width;j++)
	{
		
		rgb_t colour;
	image.get_pixel(j,i,colour);
	
	r=colour.red;
	g=colour.green;
	b=colour.blue;
	
remainder=0;
l=1;		
	
	
	
	while(r!=0)
	{
		
		
		remainder=r%2;
	    r=r/2;
	    b1=b1+(remainder*l);
	    l=l*10;
	    
	}
	
	
	
	remainder=0;
	l=1;
	
	
	while(g!=0)
	{
		
		remainder=g%2;
	    g=g/2;
	    b2=b2+(remainder*l);
	    l=l*10;
	    
	}
	
	remainder=0;
	l=1;
	while(b!=0)
	{
		
		remainder=b%2;
	    b=b/2;
	    b3=b3+(remainder*l);
	    l=l*10;
	    
	}
	
	
		
	
	count=0;
	v=7;
bina=b1;	
	while(bina!=0)
	{
		bina/=10;
		count++;
		
}	
	
	
	
	if(count==8)
	{
	
	while(b1!=0)
	{
		rc[v]=b1%10;
		b1=b1/10;
		v--;
	}
}
else
{
	rc[0]=0;
	
	while(b1!=0)
	{
		rc[v]=b1%10;
		b1=b1/10;
		v--;
	}
	
}
	v=0;
	
	

count=0;
bina=b2;
v=7;	
		while(bina!=0)
	{
		bina/=10;
		count++;
		
}
	if(count==8)
	{
	
	while(b2!=0)
	{
		gc[v]=b2%10;
		b2=b2/10;
		v--;
	}
}
else
{
	gc[0]=0;
	
	while(b2!=0)
	{
		gc[v]=b2%10;
		b2=b2/10;
		v--;
	}
	
}
	
	
	bina=b3;
	count=0;
	v=7;
		while(bina!=0)
	{
		bina/=10;
		count++;
		
}
	if(count==8)
	{
	
	while(b3!=0)
	{
		bc[v]=b3%10;
		b3=b3/10;
		v--;
	}
	
}
else
{
	bc[0]=0;
	
	while(b3!=0)
	{
		bc[v]=b3%10;
		b3=b3/10;
		v--;
	}
	
}
	if(q==8)
	goto ji;
	else
	{
	
	bt[q]=rc[7];
	q++;
    }
	if(q==8)
	goto ji;
	else
	{
	
		bt[q]=gc[7];
		q++;
	}
	if(q==8)
	goto ji;
	else
	{
	
		bt[q]=bc[7];
		q++;
	}
	
	
	
	ji:
	
		
		
		

	
	
	
	
	if(q>=8)
	{
			
		
		
		
			x=0;
			binary=bt[0];
			
			for(x=1;x<8;x++)
			{
				binary=(binary*10)+bt[x];
				
				}
		
		
		x=0;	
			
			
	while(binary!=0)
	{
		remainder=binary%10;
		binary/=10;
		n=n+remainder*(pow(2,x));
		x++;
	}
	
  cout<<"\n"<<n;
  
  char ch;
  
  ch=n;
  
  cout<<"\n the string is "<<ch;  
	
	
	return;
}
	
}

}


}


void embedtext()
{
	
		char str[20];
		cout<<"\n enter a character";
		cin>>str;
	
	
	int n=str[0];
	
	
	
	int remainder;
	int l=1;
	int k;
	k=0;
	long binary=0;
	
	cout<<n;
	
	while(n!=0)
	{
		
		remainder=n%2;
	    n=n/2;
	    binary=binary+(remainder*l);
	    l=l*10;
	    
	}
	cout<<"\n binary="<<binary;
	int count=0;
	
	int n1=n;
	long bina=binary;
	int bt[8];
	while(bina!=0)
	{
		bina/=10;
		count++;
		
}
	
	
	
	
	int v=7,v1=7;
if(count==8)
{
	while(binary!=0)
	{
		bt[v]=binary%10;
		binary=binary/10;
		v--;
	}
	
}	
else
	{
		bt[0]=0;
		while(binary!=0)
		{
			bt[v1]=binary%10;
			binary=binary/10;
			v1--;
		}
		
		
		
	}
	
	
	
	int rc[8],gc[8],bc[8];
	long b1;
	long b2;
	long b3;
	int q=0;
int charindex=0;
int charvalue=0;

long colorindex=0;
		int zeros=0;
		
		
		int r=0,g=0,b=0;
			int height=image.height();
			int width=image.width();
		
		for(std::size_t i=0;i<height;i++)
		{
		
		for(std::size_t j=0;j<width;j++)
	{
		
		rgb_t colour;
	image.get_pixel(j,i,colour);
	
	r=colour.red-(colour.red%2);
	g=colour.green-(colour.green%2);
	b=colour.blue-(colour.blue%2);
	
remainder=0;
l=1;		
	
	while(r!=0)
	{
		
		
		remainder=r%2;
	    r=r/2;
	    b1=b1+(remainder*l);
	    l=l*10;
	    
	}
	
	remainder=0;
	l=1;
	
	
	while(g!=0)
	{
		
		remainder=g%2;
	    g=g/2;
	    b2=b2+(remainder*l);
	    l=l*10;
	    
	}
	
	remainder=0;
	l=1;
	while(b!=0)
	{
		
		remainder=b%2;
	    b=b/2;
	    b3=b3+(remainder*l);
	    l=l*10;
	    
	}
	
	v=7;
	while(b1!=0)
	{
		rc[v]=b1%10;
		b1=b1/10;
		v--;
	}
	
	v=7;
	
	while(b2!=0)
	{
		gc[v]=b2%10;
		b2=b2/10;
		v--;
	}
	
	
	v=7;
	while(b3!=0)
	{
		bc[v]=b3%10;
		b3=b3/10;
		v--;
	}
	
	if(q==8)
	goto ji;
	else
	{
	rc[7]=bt[q];
	q++;
    }
	if(q==8)
	goto ji;
	else
	{
		gc[7]=bt[q];
		q++;
	}
	if(q==8)
	goto ji;
	else
	{
		bc[7]=bt[q];
		q++;
	}
	
	
	
	b1=rc[0];
	b2=gc[0];
	b3=bc[0];
	ji:
	for(int ij=1;ij<8;ij++)
	{
		b1=(b1*10)+rc[ij];
		b2=(b2*10)+gc[ij];
		b3=(b3*10)+bc[ij];
		
		}	
		
		
		r=b=g=0;
		int x=0;
		
		
		while(b1!=0)
		{
		remainder=b1%10;
		b1/=10;
		r+=remainder*(pow(2,x));
		x++;	
		}
		
		x=0;
		
		while(b2!=0)
		{
			remainder=b2%10;
			b2/=10;
			g=g+remainder*(pow(2,x));
			x++;
		}
	
	x=0;
	while(b3!=0)
	{
		remainder=b3%10;
		b3/=10;
		b=b+remainder*(pow(2,x));
		x++;
		
	}
	
	colour.red=r;
	colour.blue=b;
	colour.green=g;
	
	
	image.set_pixel(j,i,colour);
	
	if(q>=8)
	{
	
	image.save_image("test");

	cout<<"\n success";	
	return;
	}
	
}

}

	
	
	
}



};



int main()
{


    char a[20];

	cout<<"\n enter the image name";
	cin>>a;
	
	std::string file_name(a);
	stegno s;
	
	s.image=file_name;
	
	
			
	

   if (!s.image)
   {
      cout<<"\n not succes";      
   }

else
     cout<<"\n sucess";

int choice;



cout<<"\n 1.encrypt \n 2.decrypt \n enter the choice";
cin>>choice;
switch(choice)
{
	case 1:
		s.embedtext();
		break;
	case 2:
		s.detext();
		break;
}


cout<<"\n end in main";
}
