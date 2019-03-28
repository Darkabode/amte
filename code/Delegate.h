#ifndef __AMTE_DELEGATE_H_
#define __AMTE_DELEGATE_H_

namespace amte {

class DelegateBase	 
{
public:
    DelegateBase(void* pObject, void* pFn);
    DelegateBase(const DelegateBase& rhs);
    virtual ~DelegateBase();
    bool Equals(const DelegateBase& rhs) const;
    void operator() (void* param);
    virtual DelegateBase* Copy() const = 0; // add const for gcc

protected:
    void* GetFn();
    void* GetObject();
    virtual void Invoke(void* param) = 0;

private:
    void* m_pObject;
    void* m_pFn;
};

template <class O, class T>
class Delegate : public DelegateBase
{
    typedef void (T::*Fn)(void*);
public:
    Delegate(O* pObj, Fn pFn) : DelegateBase(pObj, &pFn), m_pFn(pFn) { }
    Delegate(const Delegate& rhs) : DelegateBase(rhs) { m_pFn = rhs.m_pFn; } 
    virtual DelegateBase* Copy() const { return new Delegate(*this); }

protected:
    virtual void Invoke(void* param)
    {
        O* pObject = (O*) GetObject();
        (pObject->*m_pFn)(param); 
    }  

private:
    Fn m_pFn;
};

template <class O, class T>
Delegate<O, T> MakeDelegate(O* pObject, void (T::* pFn)(void*))
{
    return Delegate<O, T>(pObject, pFn);
}

}

#endif // __AMTE_DELEGATE_H_
