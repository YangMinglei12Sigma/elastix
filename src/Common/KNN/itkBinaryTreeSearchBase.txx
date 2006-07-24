#ifndef __itkBinaryTreeSearchBase_txx
#define __itkBinaryTreeSearchBase_txx

#include "itkBinaryTreeSearchBase.h"

namespace itk
{
	
	/**
	 * ************************ Constructor *************************
	 */

	template < class TBinaryTree >
		BinaryTreeSearchBase<TBinaryTree>
		::BinaryTreeSearchBase()
	{
    this->m_BinaryTree = 0;
    this->m_KNearestNeighbors = 1;
  } // end Constructor


  /**
	 * ************************ Destructor *************************
	 */

	template < class TBinaryTree >
		BinaryTreeSearchBase<TBinaryTree>
		::~BinaryTreeSearchBase()
	{
  } // end Destructor


  /**
	 * ************************ SetBinaryTree *************************
	 */

	template < class TBinaryTree >
		void BinaryTreeSearchBase<TBinaryTree>
		::SetBinaryTree( BinaryTreeType * tree )
	{
    if ( this->m_BinaryTree != tree )
    {
      this->m_BinaryTree = tree;
			if ( tree )
			{
				this->m_DataDimension = this->m_BinaryTree->GetDataDimension();
			}
      this->Modified();
    }
  } // end SetBinaryTree


  /**
	 * ************************ GetBinaryTree *************************
	 */

	template < class TBinaryTree >
    const typename BinaryTreeSearchBase<TBinaryTree>::BinaryTreeType *
    BinaryTreeSearchBase<TBinaryTree>
		::GetBinaryTree( void ) const
	{
    return this->m_BinaryTree.GetPointer();
  } // end GetBinaryTree


} // end namespace itk


#endif // end #ifndef __itkBinaryTreeSearchBase_txx

