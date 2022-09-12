#include<iostream>
using namespace std;

//////////////////////////STRUCTURE DECLERATION//////////////////////////////////

template<class T>
struct NodeSingly
{
	T data;
	struct NodeSingly *Next;
};

template<class T>
struct NodeDoubly
{
	T data;
	struct NodeDoubly *Next;
	struct NodeDoubly *Prev;
};

/////////////////////CLASS DECLERATION WITH ABSTRACT METHODS/////////////////////////

template<class T>
class SinglyLinearLL
{
	private: 
	struct NodeSingly<T> *Head;
	
	public:
	int Count;
	
	SinglyLinearLL(); 
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T No,int Pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int Pos);
	void DisplayNode();
	int CountNode();
};

template<class T>
class SinglyCircularLL
{
    private:
    struct NodeSingly<T> *Head; 
	struct NodeSingly<T> *Tail;
    
    public:
    int iCount; 

    SinglyCircularLL(); 
    void InsertFirst(T); 
    void InsertLast(T);
    void InsertAtPos(T,int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void DisplayNode();
    int CountNode(); 
};

template<class T>
class DoublyLinearLL  
{
	private:
	struct NodeDoubly<T> *Head; 

	public:
    int iCount;
	
	DoublyLinearLL();
	void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T,int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    void DisplayNode();
    int CountNode(); 
};

template<class T>
class DoublyCircularLL //class decleartion//
{
	private:
	struct NodeDoubly<T> *Head;
	struct NodeDoubly<T> *Tail;
	
	public:
    int iCount;
	 
	DoublyCircularLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int pos);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int pos);
	void DisplayNode();
	int CountNode();	
};


//////////////////////////////////CONSTRUCTURE'S////////////////////////////

template<class T>
SinglyLinearLL<T>::SinglyLinearLL()
{
	Count = 0;
	Head = NULL;
}

template<class T>
SinglyCircularLL<T>::SinglyCircularLL()
{
    iCount = 0;
    Head = NULL;
    Tail = NULL;
}

template<class T>
DoublyLinearLL<T>::DoublyLinearLL()
{
	Head = NULL;
    iCount = 0;
}

template<class T>
DoublyCircularLL<T>:: DoublyCircularLL()
{
	Head = NULL;
	Tail = NULL;
    iCount = 0;
}

///////////////////////CONCREATE METHODS FROM ALL THE CLASSES/////////////////

/*SINGLY LINEAR LINKED LIST*/

template<class T>
void SinglyLinearLL<T>::InsertFirst(T Data)
{
	struct NodeSingly<T>* newn = NULL;
	newn = new NodeSingly<T>;
	newn->data = Data;
	newn->Next = NULL;
		
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		newn->Next = Head;
		Head = newn;
	}
	Count++;
	return;
}

template<class T>
void SinglyLinearLL<T>::InsertLast(T Data)
{
	struct NodeSingly<T>* newn = NULL;
	newn = new NodeSingly<T>;
	newn->data = Data;
	newn->Next = NULL;
		
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		struct NodeSingly<T> *temp = Head;
			
		while(temp->Next != NULL)
		{
			temp = temp->Next;
		}
		temp->Next = newn;	 
	}
	Count++;
	return;
}

template<class T>
void SinglyLinearLL<T>::InsertAtPos(T Data,int Pos)
{
	if(Pos == 1)
	{
		InsertFirst(Data);
	}
	else if(Pos == (Count + 1))
	{
		InsertLast(Data);
	}
	else if((Pos < 1)||(Pos >(Count+1)))
	{
		cout<<"Invalid Position";
		return;
	}
	else
	{
		struct NodeSingly<T> *newn = NULL;
		newn = new NodeSingly<T>;
		newn->data = Data;
		newn->Next = NULL;
		
		struct NodeSingly<T> *temp = Head;
		for(int i = 1;i < (Pos - 1);i++)
		{
			temp = temp->Next;
		}
		newn->Next = temp->Next;
		temp->Next = newn;
	}
	Count++;
 return;
}

template<class T>
void SinglyLinearLL<T>::DeleteFirst()
{
	if(Head == NULL)
	{
		cout<<"LL is empty";
		return;
	}
	else
	{
		struct NodeSingly<T> *temp = Head;
		Head = Head->Next;
		delete temp;
		Count--;
	}
 return;
}

template<class T>
void SinglyLinearLL<T>::DeleteLast()
{
	if(Head == NULL)
	{
		cout<<"LL is empty";
		return;
	}
	else
	{
		struct NodeSingly<T> *temp = Head;
			
		while(temp->Next->Next != NULL)
		{
			temp = temp->Next;
		}
		delete (temp->Next);
		temp->Next = NULL;
		Count--;
	}
	return;
}

template<class T>
void SinglyLinearLL<T>::DeleteAtPos(int Pos)
{
	if(Pos == 1)
	{
		DeleteFirst();
	}
	else if(Pos == Count)
	{
		DeleteLast();
	}
	else if((Pos < 1)||(Pos >Count))
	{
		cout<<"Invalid Position";
		return;
	}
	else
	{
		struct NodeSingly<T> *temp = Head;
		struct NodeSingly<T> *temp1 = NULL;
		for(int i = 1;i < (Pos - 1);i++)
		{
			temp = temp->Next;
		}
		temp1 = temp->Next;
		temp->Next = temp1->Next;
		delete (temp1);
	}
	Count--;
 return;
}

template<class T>
void SinglyLinearLL<T>::DisplayNode()
{
	//cout<<"Elements of Singly Linear linked list are: "<<endl;
	struct NodeSingly<T>*temp = Head;
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->Next;
	}
	cout<<endl;
	return;
}

template<class T>
int SinglyLinearLL<T>::CountNode()
{
	return Count;	
}

/*SINGLY CIRCULAR LINKED LIST*/

template<class T>
void SinglyCircularLL<T>::InsertFirst(T Data)
{
    struct NodeSingly<T> *newn = NULL;
    newn = new NodeSingly<T>; 
    newn->data = Data;
    newn->Next = NULL;

    if((Head == NULL)&&(Tail == NULL))
    {
        Head = newn;
        Tail = newn;   
    }
    else
    {
        newn->Next = Head;
        Head = newn;
    }
    Tail->Next = Head;
    iCount++;
	return;
}

template<class T>
void SinglyCircularLL<T>::InsertLast(T Data)
{
    struct NodeSingly<T>*newn = NULL;
    newn =  new NodeSingly<T>;

    newn->data = Data;
    newn->Next = NULL;

    if((Head == NULL)&&(Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->Next = newn;
        Tail = newn;
    }
    Tail->Next = Head;
    iCount++;
	return;
}

template<class T>
void SinglyCircularLL<T>::InsertAtPos(T Data,int iPos)
{
    int i = 0;

    if(iPos == 1)
    {
        InsertFirst(Data);
        return;
    }
    else if(iPos == (iCount+1))
    {
        InsertLast(Data);
        return;
    }
    else if((iPos < 1)||(iPos > iCount+1))
    {
        cout<<"Invalid Position.";
        return;
    }
    else
    {
        struct NodeSingly<T> *temp = Head;
        struct NodeSingly<T> *newn = NULL;
        newn = new NodeSingly<T>;
        newn->data = Data;
        newn->Next = NULL;

        for(i = 1;i<(iPos-1);i++)
        {
            temp = temp->Next;
        }
        newn->Next = temp->Next;
        temp->Next = newn;
    }
    Tail->Next = Head;
    iCount++;
	return;
}

template<class T>
void SinglyCircularLL<T>::DeleteFirst()
{
    if((Head == NULL)&&(Tail == NULL))
    {
        cout<<"Linked List is empty.";
        return;
    }
    else
    {
        Head = Head->Next;
        delete Tail->Next;
    }
    Tail->Next = Head;
    iCount--;
	return;
}

template<class T>
void SinglyCircularLL<T>::DeleteLast()
{
    if((Head == NULL)&&(Tail == NULL))
    {
        cout<<"Linked List is empty.";
        return;
    }
    else
    {
        struct NodeSingly<T> *temp = Head;
        while(temp->Next->Next != Head)
        {
            temp = temp->Next;
        }
        delete(Tail);
        Tail = temp;
    }
    Tail->Next = Head;
    iCount--;
	return;
}

template<class T>
void SinglyCircularLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;

    if(iPos == 1)
    {
        DeleteFirst();
        return;
    }
    else if(iPos == iCount+1)
    {
        DeleteLast();
        return;
    }
    else if((iPos < 1)||(iPos > iCount+1))
    {
        cout<<"Invalid Position to delete the node.";
        return;
    }
    else
    {
        struct NodeSingly<T> *temp1 = Head;
        struct NodeSingly<T> *temp2 = NULL;
        for(i=0;i<iPos-1;i++)
        {
            temp1 = temp1->Next;
        }
        temp2 = temp1->Next;
        temp1->Next = temp2->Next;
        delete(temp2);
    }
    Tail->Next = Head;
    iCount--;
	return;
}

template<class T>
void SinglyCircularLL<T>::DisplayNode()
{
    struct NodeSingly<T>*temp = Head;
    do
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->Next;
	}while(temp != Head);
    cout<<"\n";
    return;
}

template<class T>
int SinglyCircularLL<T>::CountNode()
{
    return iCount;
}

/*DOUBLY LINEAR LINKED LIST*/

template<class T>
void DoublyLinearLL<T>::InsertFirst(T Data)
{
	struct NodeDoubly<T> *newn = NULL;
	newn = new NodeDoubly<T>;

	newn->Next = NULL;
	newn->data = Data;
	newn->Prev = NULL;
		
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		newn->Next = Head;
		Head->Prev = newn;
		Head = newn;
	}
    iCount++;
	return;
}

template<class T>
void DoublyLinearLL<T>::InsertLast(T Data)
{
	struct NodeDoubly<T> *newn = NULL;
	newn = new NodeDoubly<T>;
		
	newn->Next = NULL;
	newn->Prev = NULL;
	newn->data = Data;
		
	if(Head == NULL)
	{
		Head = newn;
	}
	else
	{
		struct NodeDoubly<T> *temp = NULL;
		temp = Head;
			
		while(temp->Next != NULL)
		{
			temp = temp->Next;
		}
		temp->Next = newn;
		newn->Prev = temp;
	}
    iCount++;
	return;
}

template<class T>	
void DoublyLinearLL<T>::InsertAtPos(T Data,int pos)
{
	int i = 0;

	if(pos == 1)
	{
		InsertFirst(Data);
        return;
	}
	else if(pos == (iCount+1))
	{
		InsertLast(Data);
    	return;
	}
	else if((pos < 1)||(pos >(iCount+1)))
	{
		cout<<"Invalid position";
		return;
	}
	else
	{
		struct NodeDoubly<T> *newn = NULL;
		newn = new NodeDoubly<T>;

		newn->data = Data;
		newn->Next = NULL;
		newn->Prev = NULL;
			
		struct NodeDoubly<T> *temp = NULL;
		temp = Head;
			
		for(i = 1; i <(pos-1); i++)
		{
			temp = temp->Next;
		}

		newn->Next = temp->Next;
		temp->Next->Prev = newn;
		newn->Prev = temp;
		temp->Next = newn;
	}
    iCount++;
	return;
}

template<class T>
void DoublyLinearLL<T>::DeleteFirst()
{
	if(Head == NULL)
	{
		cout<<"Linked List is empty.";
		return;
	}
	else
	{
		Head = Head->Next;
		delete Head->Prev;
		Head->Prev = NULL;
	}
	iCount--;
	return;
}

template<class T>
void DoublyLinearLL<T>::DeleteLast()
{
	if(Head == NULL)
	{
		cout<<"Linked List is empty.";
		return;
	}
	else
	{
		struct NodeDoubly<T> *temp = Head;

		while((temp->Next->Next) != NULL)
		{
			temp = temp->Next;
		}

		delete temp->Next;
		temp->Next = NULL;	
	}
    iCount--;
	return;
}

template<class T>
void DoublyLinearLL<T>::DeleteAtPos(int pos)
{	
    int i = 0;

	if(Head == NULL)
	{
		cout<<"Linked list is empty.";
		return;
	}
	if((pos < 1)||(pos > (iCount+1)))
	{
		cout<<"Invalid position to insert the node.";
		return;
	}
	if(pos == 1)
	{
		DeleteFirst();
        return;
	}
	if(pos == (iCount+1))
	{
		DeleteLast();
        return;
	}
	else
	{
		struct NodeDoubly<T> *temp = NULL;
		temp = Head;
		for(i = 1; i < (pos-1);i++)
		{
			temp = temp->Next;
		}

		temp->Next = temp->Next->Next;
		delete temp->Next->Prev;
		temp->Next->Prev = temp;	
	}
	iCount--;
	return;
}

template<class T>
void DoublyLinearLL<T>::DisplayNode()
{
	struct NodeDoubly<T> *temp = Head;
		
	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->Next;
	}
	cout<<"\n";
	return;
}

template<class T>
int DoublyLinearLL<T>::CountNode()
{
	return iCount;
}	

/*DOUBLY CIRCULAR LINKED LIST*/

template<class T>
void DoublyCircularLL<T>:: InsertFirst(T Data)
{
	struct NodeDoubly<T> *newn = NULL;
	newn = new NodeDoubly<T>;

	newn->Next = NULL;
	newn->Prev = NULL;
	newn->data = Data;
		
	if((Head == NULL)&&(Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->Next = Head;
		Head->Prev = newn;
		newn->Prev = Tail;
		Head = newn;
	}

	Tail->Next = Head;
	Head->Prev = Tail;
    iCount++;
	return;
}

template<class T>
void DoublyCircularLL<T>:: InsertLast(T Data)
{
	struct NodeDoubly<T> *newn = NULL;
	newn = new NodeDoubly<T>;

	newn->data = Data;
	newn->Next = NULL;
	newn->Prev = NULL;
		
	if((Head == NULL)&&(Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->Next = newn;
		newn->Prev = Tail;
		Tail = newn; 
	}
	Tail->Next = Head;
	Head->Prev = Tail;
    iCount++;
	return;
}

template<class T>
void DoublyCircularLL<T>:: InsertAtPos(T Data, int pos)
{
    int i = 0;
	if(pos == 1)
	{
		InsertFirst(Data);
        return;
	}
	else if(pos == (iCount+1))
	{
		InsertLast(Data);
        return;
	}
	else if((pos<1)||(pos >(iCount+1)))
	{
		cout<<"Invalid Position to insert the node.";
		return;
	}
	else
	{
		struct NodeDoubly<T> *newn = NULL;
		newn = new NodeDoubly<T>;

		newn->data = Data;
		newn->Next = NULL;
		newn->Prev = NULL;
			
		struct NodeDoubly<T> *temp = Head;
			
		for(i = 1; i <(pos - 1); i++)
		{
			temp = temp->Next;
		}

		newn->Next = temp->Next;
		temp->Next->Prev = newn;
		newn->Prev = temp;
		temp->Next = newn;
	}
	Tail->Next = Head;
	Head->Prev = Tail;
    iCount++;
	return;
}

template<class T>
void DoublyCircularLL<T>:: DeleteFirst()
{
	if((Head == NULL)&&(Tail == NULL))
	{
		cout<<"Linked list is empty.";
		return;
	}	
	else
	{
		Head = Head->Next;
		delete Head->Prev;
	}
	Tail->Next = Head;
	Head->Prev = Tail;
    iCount--;
	return;
}

template<class T>
void DoublyCircularLL<T>:: DeleteLast()
{
	if((Head == NULL)&&(Tail == NULL))
	{
		cout<<"Linked list is empty.";
		return;
	}	
	else
	{
		Tail = Tail->Prev;
		delete Tail->Next;	
	}
	Tail->Next = Head;
	Head->Prev = Tail;
    iCount--;
	return;
}

template<class T>
void DoublyCircularLL<T>:: DeleteAtPos(int pos)
{
    int i = 0;
	if(pos == 1)
	{
		DeleteFirst();
        return;
	}
	else if(pos == (iCount))
	{
		DeleteLast();
        return;
	}
	else if((pos<1)||(pos >(iCount+1)))
	{
		cout<<"Invalid Position to delete the node.";
		return;
	}
	else
	{
		struct NodeDoubly<T> *temp = Head;

		for(i = 1; i<(pos - 1); i++)
		{
			temp = temp->Next;
		}

		struct NodeDoubly<T> *tempdelete = NULL;
		tempdelete = temp->Next;
		temp->Next = tempdelete->Next;
		tempdelete->Next->Prev = temp;
		delete tempdelete;
	}
	Tail->Next = Head;
	Head->Prev = Tail;
    iCount--;
	return;
}

template<class T>
void DoublyCircularLL<T>:: DisplayNode()
{
	struct NodeDoubly<T> *temp = Head;
	do
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->Next;
		
	}while(temp!= Head);
	cout<<"\n";
	return;
}
	
template<class T>
int DoublyCircularLL<T>:: CountNode()
{
	return iCount;
}

/*ENTRY POINT FUNCTION*/
int main()
{
	int iret = 0;
	SinglyLinearLL<int>obj1;
	obj1.DisplayNode();
	iret = obj1.CountNode();
	cout<<"Number of node in singly linear ll is:"<<iret<<endl;

	SinglyCircularLL<int>obj2;
	iret = 0;
	obj2.DisplayNode();
	iret = obj2.CountNode();
	cout<<"Number of node in singly circular ll is:"<<iret<<endl;

	DoublyLinearLL<int>obj3;
	iret = 0;
	obj3.DisplayNode();
	iret = obj3.CountNode();
	cout<<"Number of node in doubly linear ll is:"<<iret<<endl;

	DoublyCircularLL<int>obj4;
	iret = 0;
	obj4.DisplayNode();
	iret = obj4.CountNode();
	cout<<"Number of node in doubly circular ll is:"<<iret<<endl;
 return 0;
}