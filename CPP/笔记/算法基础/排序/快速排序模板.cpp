class Solution 
{
public:
    int partition(vector<int>& nums, int l, int r)
    {
        int mid = l + rand() % (r - l + 1);
        int mv = nums[mid];
        swap(nums[l], nums[mid]);

        int i = l + 1, j = r;
        while(true)
        {
            while(i <= j && nums[i] < mv) i++;
            while(i <= j && nums[j] > mv) j--;

            if(i >= j) break;

            swap(nums[i], nums[j]);
            i++, j--;
        }
        swap(nums[l], nums[j]);

        return j;
    }

    void quickSort(vector<int>& nums, int l, int r)
    {
        // STL д����is_sorted(nums.begin() + left, nums.begin() + right + 1)
        bool flag = true;
        for(int i = l; i < r; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                flag = false;
                break;
            }
        }

        if(flag) return;

        int i = partition(nums, l, r);
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        srand(time(0));
        int n = nums.size();
        quickSort(nums, 0, n - 1);

        return nums;
    }
};

// ʾ�� 1��
// ���룺nums = [5,2,3,1]
// �����[1,2,3,5]
// ���ͣ����������ĳЩ���ֵ�λ��û�иı䣨���磬2 �� 3�������������ֵ�λ�÷����˸ı䣨���磬1 �� 5����


// ʾ�� 2��
// ���룺nums = [5,1,1,2,0,0]
// �����[0,0,1,1,2,5]
// ���ͣ���ע�⣬nums ��ֵ��һ��Ψһ��