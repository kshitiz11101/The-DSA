class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // code here
        vector<int> Vodd, Veven;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                Veven.push_back(temp->data);
            }
            else
            {
                Vodd.push_back(temp->data);
            }
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < Veven.size(); i++)
        {
            temp->data = Veven[i];
            temp = temp->next;
        }
        for (int i = 0; i < Vodd.size(); i++)
        {
            temp->data = Vodd[i];
            temp = temp->next;
        }
        return head;
    }
};