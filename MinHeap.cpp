#include <vector>

template <class T>
class Min_Heap
{
public:
    Min_Heap();
    const T& Top() const;
    void Push(const T& e);
    T Pop();
    bool isEmpty();
private:
    void shift_up(unsigned int hole_index, const T& e);
    void shift_down(unsigned int hole_index, const T& e);
private:
    std::vector<T> data_;
    size_t size_;
};

template<class T>
inline Min_Heap<T>::Min_Heap():size_(0)
{
}

template<class T>
inline const T & Min_Heap<T>::Top() const
{
    if (data_.empty() || size_ == 0)
        throw std::logic_error("Heap is Empty!");

    return data_[0];
}

template<class T>
inline void Min_Heap<T>::Push(const T & e)
{
    data_.push_back(e);
    ++size_;
    shift_up(size_ - 1, e);
}

template<class T>
inline T Min_Heap<T>::Pop()
{
    if (data_.empty() || size_ == 0)
        throw std::logic_error("Heap is Empty!");

    --size_;
    T e = data_[0];
    shift_down(0, data_[size_]);
    return e;
}

template<class T>
inline bool Min_Heap<T>::isEmpty()
{
    if (size_ == 0)
        return true;
    return false;
}

template<class T>
inline void Min_Heap<T>::shift_up(unsigned int hole_index, const T & e)
{
    unsigned int parentIdx = (hole_index - 1) / 2;
    while (hole_index && (data_[parentIdx] > e))
    {
        data_[hole_index] = data_[parentIdx];
        hole_index = parentIdx;
        parentIdx = (hole_index - 1) / 2;
    }
    data_[hole_index] = e;
}

template<class T>
inline void Min_Heap<T>::shift_down(unsigned int hole_index, const T & e)
{
    unsigned int minChild = 2 * (hole_index + 1);
    while (minChild <= size_)
    {
        minChild -= ((minChild == size_) || (data_[minChild] > data_[minChild - 1]));
        if (e <= data_[minChild])
            break;
        data_[hole_index] = data_[minChild];
        hole_index = minChild;
        minChild = 2 * (hole_index + 1);
    }
    data_[hole_index] = e;
}