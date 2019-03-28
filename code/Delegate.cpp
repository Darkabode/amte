#include "common.h"
#include "Delegate.h"

namespace amte {

DelegateBase::DelegateBase(void* pObject, void* pFn) 
{
    m_pObject = pObject;
    m_pFn = pFn; 
}

DelegateBase::DelegateBase(const DelegateBase& rhs) 
{
    m_pObject = rhs.m_pObject;
    m_pFn = rhs.m_pFn; 
}

DelegateBase::~DelegateBase()
{

}

bool DelegateBase::Equals(const DelegateBase& rhs) const 
{
    return m_pObject == rhs.m_pObject && m_pFn == rhs.m_pFn; 
}

void DelegateBase::operator() (void* param) 
{
    Invoke(param); 
}

void* DelegateBase::GetFn() 
{
    return m_pFn; 
}

void* DelegateBase::GetObject() 
{
    return m_pObject; 
}

}
