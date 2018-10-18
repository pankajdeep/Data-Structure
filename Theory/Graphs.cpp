#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class GRAPH
{
	int v,e;
	node **start;
	public:
		GRAPH(int ver,int edg)
		{
			start = new node*[ver];
			v = ver;
			e = edg;
		}
		void create_graph()
		{
			int val;
			for(int i=0;i<v;i++)
			{
				
				start[i] = NULL;
			}
			for(int i=0;i<v;i++)
			{
				cout<<"Enter the nodes to be connected for "<<i<<" node and press -1 to stop\n";
				cin>>val;
				node *temp = new node;
				while(val != -1)
				{
					temp->data = val;
					temp->next = NULL;
					if(start[i] == NULL)
					{
						start[i] = temp;
					}
					else
					{
						node *ptr;
						ptr=start[i];
						while(ptr!= NULL)
							ptr = ptr->next;
						ptr= temp;
					
					}
					cin>>val;
				}
			}
		}
		void display()
		{
			node *ptr;
			cout<<"The adjancy list is\n";
			for(int i=0;i<v;i++)
			{
				ptr = start[i];
				while(ptr!=NULL)
				{
					cout<<ptr->data<<"\t";
					ptr = ptr->next;
				}
				cout<<endl;
			}
		}
};
int main()
{
	int ver,edg;
	cout<<"Enter number of vertices and number of  edges\n";
	cin>>ver>>edg;
	GRAPH g(ver,edg);
	g.create_graph();
	g.display();
}
