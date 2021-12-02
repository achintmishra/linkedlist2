#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
  public:
  int data;
  node *next;
  node (int data)
  {
    this->data=data;
    next=NULL;
  }
};
node *takeinput()
{
  int data;
  cin>>data;
  node *head =NULL;
  node *tail=NULL;
  while(data!=-1)
  {
    node *newnode = new node(data);
    if(head==NULL)
    {
      head=newnode;
      tail=newnode;
    }
    else
    {
      tail->next = newnode;
      tail=tail->next;
    }
    cin>>data;
  }
  return head;
}
node *print(node *head)
{
  while(head!=NULL)
  {
    cout<<head->data<<" ";
    head = head->next;
  }
  return head;
}
node *evenafterodd(node *head)
{
  if(head==NULL)
  {
    return head;
  }
    node *evenhead=NULL;
    node *eventail=NULL;
    node *oddhead=NULL;
    node *oddtail=NULL;
  while(head!=NULL)
  {
    if(head->data%2==0)
    {
      if(evenhead==NULL)
      {
        evenhead=head;
        eventail=head;
      }
      else
      {
        eventail->next=head;
        eventail=eventail->next;
      }
    }
    else
    {
      if(oddhead==NULL)
      {
        oddhead=head;
        oddtail=head;
      }
      else
      {
        oddtail->next=head;
        oddtail=oddtail->next;
      }
    }
    head=head->next;
  }
  if(oddhead==NULL)
  {
    return evenhead;
  }
  else
  {
    oddtail->next=evenhead;
  }
  if(evenhead!=NULL)
  {
    eventail->next=NULL;
  }
  return oddhead;
}
node *deleteNnodes(node*head,int m, int n)
{
  if(m==0||head==NULL)
  {
    return NULL;
  }
  if(n==0)
  {
    return head;
  }
  int go=0;
  int skip=0;
  node *temp1= head;
  while(go<m || head!=NULL)
  {
    temp1->next=head;
    temp1=temp1->next;
    go++;
    head=head->next;
  }
  if(head!=NULL)
  {
    head->next=NULL;
  }
  return head;
}
int main()
{
  node *head = takeinput();
  print(head);
  cout<<endl;
  node *deletion = deleteNnodes(head,3,2);
  print(deletion);
}