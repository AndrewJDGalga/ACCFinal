/*
 * NAME: Andrew J
 * COSC 2436
 * PURPOSE:
 *    LINKED LIST IMPLEMENTATION
 *      The following implementation file expands upon the design laid out in linkedlist.h
 */

#include "linkedlist.h"


//constructor to set head pointer to null
LinkedList::LinkedList()
{
  head = NULL;
}


//destructor to clear linked list
LinkedList::~LinkedList()
{
  clear();
}


LinkedList::operator bool() const //found this online, allows boolean tests when in array, keeping?
{
    bool validHead = false;
    if(head)
    {
        validHead = true;
    }
    return validHead;
}


/*
  The following method takes in an integer ID and string data,
  checks if header pointer is valid
    if not and ID > 0
      create and assign first node with link to head pointer
    if yes and ID > 0
      check if ID has been used
        if duplicate ID
          return failure
        else
          create node and insert into ordered position (smallest to largest)
*/
bool LinkedList::addNode(int newID, int weight, string* newData)
{
  bool success = false;
  Node *current = head;

  if(newID > 0 && *newData != "" && current)
  {
    while(current && current->data.id != newID && !success)
    {
      if(newID < current->data.id && !current->prev)
      {
        addHead(newID, weight, newData, current);
        success = true;
      }

      if(newID > current->data.id && !current->next)
      {
        addTail(newID, weight, newData, current);
        success = true;
      }

      if(newID > current->data.id && newID < current->next->data.id)
      {
        addMid(newID, weight, newData, current);
        success = true;
      }

      current = current->next;
    }
  }
  else if(!current && newID > 0 && *newData != "")
  {
    addHead(newID, weight, newData, current);
    success = true;
  }

  return success;
}


/*
  The following helper function recieves a previously verified ID,
    a string of previously-verified data,
    and a passed node.
      creates a new node
      adds node to start of list by updating pointers
*/
void LinkedList::addHead(int newID, int weight, string* newData, Node *current)
{
  Node *newHead = new Node;
  newHead->data = {newID, weight, *newData};
  newHead->prev = NULL;
  if(current)
  {
    newHead->next = current;
    current->prev = newHead;
  }
  else
  {
    newHead->next = NULL;
  }
  head = newHead;
}


/*
  The following helper function recieves a previously verified ID,
    a string of previously-verified data,
    and a passed node.
      creates a new node
      adds node to middle of list by updating pointers
*/
void LinkedList::addMid(int newID, int weight, string* newData, Node *current)
{
  Node *mid = new Node;
  mid->data = {newID, weight, *newData};
  mid->prev = current;
  mid->next = current->next;
  current->next->prev = mid;
  current->next = mid;
}

/*
  The following helper function recieves a previously verified ID,
    a string of previously-verified data,
    and a passed node.
      creates a new node
      adds node to end of list by updating pointers
*/
void LinkedList::addTail(int newID, int weight, string* newData, Node *current)
{
    Node *last = new Node;
    last->data = {newID, weight, *newData};
    last->next = NULL;
    last->prev = current;
    current->next = last;
}


bool LinkedList::changeNodeContent(int targetID, Data* newData)
{
    bool success = false;
    bool tail = false;
    Node *current = head;

    if(current)
    {
        while(!tail && current->data.id != targetID)
        {
            if(current->next)
            {
                current = current->next;
            }
            else
            {
                tail = true;
            }
        }

        if(current->data.id == targetID)
        {
            current->data = *newData;
            success = true;
        }
    }

  return success;
}


/*
  The following method iterates through a list of nodes in search of a provided ID.
    If ID found
      send to private method for deletion
      return success
    else
      return fail
*/
bool LinkedList::deleteNode(int targetID)
{
  bool success = false;
  Node *current = head;

    if(targetID > 0)
    {
        while(current && current->data.id != targetID)
        {
            current = current->next;
        }

        if(current && current->data.id == targetID)
        {
            deleteNode(current);
            success = true;
        }
    }

  return success;
}


/*
  Private method to delete passed target node by position in linked list.
*/
void LinkedList::deleteNode(Node* target)
{
  if(target->next && target->prev) //middle
  {
    target->prev->next = target->next;
    target->next->prev = target->prev;
  }
  else if(target->next && !target->prev) //head
  {
    head = target->next;
    target->next->prev = NULL;
  }
  else if(!target->next && target->prev) //tail
  {
    target->prev->next = NULL;
  }
  else if(!target->next && !target->prev) //1 object
  {
    head = NULL;
  }

  delete target;
  target = NULL;
}


/*
  The following method searches forward through a linked list for a provided ID.
    If ID found
      end loop
      pass data within node associated to ID to variable for return
      return success
    else
      return fail
*/
bool LinkedList::getNode(int targetID, Data* targetNodeData)
{
    bool success = false;
    bool tail = false;
    Node *current = head;

        if(current)
        {
            while(!tail && current->data.id != targetID)
            {
                if(current->next)
                {
                    current = current->next;
                }
                else
                {
                    tail = true;
                }
            }

            if(current->data.id == targetID)
            {
                *targetNodeData = current->data;
                success = true;
            }
        }

    return success;
}


/*
  The following method iterates through a linked list forward or backward
  in response to being passed true or not.
    Defaults to false = forward iteration
*/
void LinkedList::printList(bool reverseOrder)
{
  Node *current = head;
  bool tail = false;

  while(current && !tail)
  {
    if(!reverseOrder) //cout outside other if as current->next logic seems to quit before last node
    {
      cout << current->data.id << " : " << current->data.data << endl;
    }

    if(current->next)
    {
      current = current->next;
    }
    else
    {
      tail = true;
    }

  }

  while(current && reverseOrder)
  {
    cout << current->data.id << " : " << current->data.data << endl;
    current = current->prev;
  }
}


/*
  The following method iterates through list once and counts up every object found.
    returns count.
*/
int LinkedList::getCount()
{
  int totalCount = 0;
  Node *current = head;

  while(current)
  {
    totalCount++;
    current = current->next;
  }

  return totalCount;
}


/*
  The following method clears a linked list by iterating first through the
  entire list forwards until the end of the list is found. Once the list end
  is found:
    iterate through backwards
    deallocate allocated memory found
    set pointer to null
    loop until head pointer reached
      set head pointer to null
  return success
  If head is already NULL,
    return false
*/
bool LinkedList::clear()
{
  bool success = false;
  bool tail = false;
  int numberObjects = 0;
  Node *current = head;
  Node *temp = NULL;

  if(current)
  {
    //iterating forwards to find the end
    while(current && !tail)
    {
      if(current->next)
      {
        current = current->next;
      }
      else
      {
        tail = true;
      }
    }
    //deleting from end
    while(current)
    {
      temp = current;
      current = current->prev;
      delete temp;
      temp = NULL;
    }

    head = NULL;
    success = true;
  }

  return success;
}


/*
  The following method iterates through a linked list testing to see
  if the ID of the linked object matches a target ID.
    If a match is found
      return true
    else
      return false
*/
bool LinkedList::exists(int targetID)
{
    Node* found = NULL;
    bool success = false;

    if(targetID > 0)
    {
        found = search(targetID);
    }

    if(found)
    {
        success = true;
    }

  return success;
}


bool LinkedList::headAlive() //todo: vector seems to initialize everything, so what to do about it?
{
    return head ? 1 : 0;
}

bool LinkedList::headAlone()
{
    return (head && !head->next) ? 1 : 0;
}

int LinkedList::nextID(int prevID)
{
    Node* next = NULL;
    int nextID = 0;

    if(prevID > 0)
    {
        next = search(prevID);

        if(next && next->next)
        {
            nextID = next->next->data.id;
        }
    }

    return nextID;
}


Node* LinkedList::search(int targetID) //assumes targetID already checked for validity
{
    bool tail = false;
    Node *current = head;
    Node *found = NULL;
    
    if(current)
    {
        while(!tail && current->data.id != targetID)
        {
            if(current->next)
            {
                current = current->next;
            }
            else
            {
                tail = true;
            }
        }

        if(current->data.id == targetID)
        {
            found = current;
        }
    }

    return found;
}