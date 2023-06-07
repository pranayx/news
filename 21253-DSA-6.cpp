#include <iostream>
#include <queue>
#include<stack>
using namespace std;
#define MAX 10
#define TRUE 1
#define FALSE 0

// declaring an adjacency list for storing the graph
class lgra
{
    private:
    struct node1
    {
        int vertex;
        struct node1 *next;
    };
    node1 *head[MAX];
    int visited[MAX];

    public:
    //static int nodecount;
    lgra();
    void create();
    void dfs(int);
    void bfs(int);
    void printAdjList();
};

//constructor
lgra::lgra()
{
    int v1;
    for (v1 = 0; v1 < MAX; v1++)
        visited[v1] = FALSE;
    for (v1 = 0; v1 < MAX; v1++)
        head[v1] = NULL;
}

void lgra::create()
{
    int v1, v2;
    char ans;
    node1 *N, *first;
    cout << "Enter the vertices number : ";
    do
    {
        cout << "\nEnter the Edge of a graph : \n";
        cin >> v1 >> v2;
        if (v1 >= MAX || v2 >= MAX)
            cout << "Invalid Vertex Value!!\n";
        else
        {
            //creating link from v1 to v2
            N = new node1;
            if (N == NULL)
                cout << "Insufficient Memory!!\n";
            N->vertex = v2;
            N->next = NULL;
            first = head[v1];
            if (first == NULL)
                head[v1] = N;
            else
            {
                while (first->next != NULL)
                    first = first->next;
                first->next = N;
            }
            //creating link from v2 to v1
            N = new node1;
            if (N == NULL)
                cout << "Insufficient Memory!!\n";
            N->vertex = v1;
            N->next = NULL;
            first = head[v2];
            if (first == NULL)
                head[v2] = N;
            else
            {
                while (first->next != NULL)
                    first = first->next;
                first->next = N;
            }
        }
        cout << "\n Want to add more edges?(y/n) : ";
        cin >> ans;
    } while (ans == 'y');
}

// print adjacency list
void lgra::printAdjList()
{
    for (int v1 = 0; v1 < MAX; v1++)
    {
        cout << v1 << " -> ";
        node1 *first =head[v1];
        while (first != NULL)
        {
            cout << first->vertex << " ";
            first = first->next;
        }
        cout << endl;
    }
}


void lgra::dfs(int v1)
{   
      int v;
    for (v = 0; v < MAX; v++)
        visited[v] = FALSE;
    stack<int>s;
    s.push(v1);
    visited[v1]=TRUE;
    while(!s.empty()){
        int currentvertex=s.top();
        cout<<currentvertex<<" ";
        s.pop();
        node1* first=head[currentvertex];
        while(first!=NULL){
            int adjvertex= first->vertex;
            if(visited[adjvertex]==FALSE){
                visited[adjvertex]=TRUE;
                s.push(adjvertex);
            }
            first=first->next;
        }
    }

}

void lgra::bfs(int startVertex) {
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = TRUE;

    while (!q.empty()) {
        int currentVertex = q.front();
        cout << currentVertex << " ";
        q.pop();

        node1* first = head[currentVertex];
        while (first != NULL) {
            int adjVertex = first->vertex;
            if (visited[adjVertex] == FALSE) {
                visited[adjVertex] = TRUE;
                q.push(adjVertex);
            }
            first = first->next;
        }
    }
}

int main()
{
    int v1;
    lgra g;
    bool repeat =true;

    while(repeat)
    {
        cout<<endl;
        cout<<" ***** MENU ***** "<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Adjacency List"<<endl;
        cout<<"3. DFS"<<endl;
        cout<<"4. BFS"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<endl;

        int choice;
        cout<<"Enter choice :";
        cin>>choice;

        switch(choice)
        {
            case 1:
            g.create();
            break;

            case 2:
            g.printAdjList();
            break;

            case 3:
            cout << endl << "Enter the vertex from where you want to traverse : ";
            cin >> v1;
            if (v1 >= MAX)
                cout << "Invalid Vertex!!\n";
            else
            {
                cout << "The Dfs of the graph : ";
                g.dfs(v1);
            }
            break;

            case 4:
            cout << endl << "Enter the vertex from where you want to traverse : ";
            cin >> v1;
            if (v1 >= MAX)
                cout << "Invalid Vertex!!\n";
            else {
                cout << "The BFS of the graph : ";
                g.bfs(v1);
            }
            break;


            case 5:
            cout<<"Exiting the code"<<endl;
            repeat = false;
            break;

            default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }
    return 0;
}