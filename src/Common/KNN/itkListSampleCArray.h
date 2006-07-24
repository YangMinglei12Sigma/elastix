#ifndef __itkListSampleCArray_h
#define __itkListSampleCArray_h

#include "itkObjectFactory.h"
#include "itkListSampleBase.h"

namespace itk{
namespace Statistics
{
	
	/**
	 * \class ListSampleCArray
	 *
	 * \brief 
	 *
	 * 
	 * \ingroup Metrics?
	 */
	
  template < class TMeasurementVector, class TInternalValue = typename TMeasurementVector::ValueType >
	class ListSampleCArray
    : public ListSampleBase< TMeasurementVector >
	{
	public:
		
		/** Standard itk. */
		typedef ListSampleCArray            Self;
		typedef ListSampleBase<
      TMeasurementVector >		          Superclass;
		typedef SmartPointer< Self >				Pointer;
		typedef SmartPointer< const Self >	ConstPointer;
		
		/** New method for creating an object using a factory.*/
		itkNewMacro( Self );
		
		/** ITK type info */
		itkTypeMacro( ListSampleCArray, ListSampleBase );

    /** Typedef's from Superclass. */
    typedef typename Superclass::MeasurementVectorType      MeasurementVectorType;
    typedef typename Superclass::MeasurementVectorSizeType  MeasurementVectorSizeType;
    typedef typename Superclass::MeasurementType            MeasurementType;
    typedef typename Superclass::FrequencyType              FrequencyType ;
    typedef typename Superclass::TotalFrequencyType         TotalFrequencyType ;
    typedef typename Superclass::InstanceIdentifier         InstanceIdentifier;
    typedef typename Superclass::SearchResultVectorType     SearchResultVectorType;
    
    /** Typedef's for the internal data container. */
    typedef TInternalValue          InternalValueType;
    typedef InternalValueType *     InternalDataType;
    typedef InternalDataType *      InternalDataContainerType;

    /** Macro to get the internal data container. */
    itkGetConstMacro( InternalContainer, InternalDataContainerType );

    /** Function to resize the data container. */
    void Resize( unsigned long n );

    /** Function to set the actual (not the allocated) size of the data container. */
    void SetActualSize( unsigned long n );

    /** Function to get the actual (not the allocated) size of the data container. */
    unsigned long GetActualSize( void );
    
    /** Function to clear the data container. */
    void Clear( void );

    /** Function to get the size of the data container. */
    unsigned int Size( void ) const
    {
      return static_cast<unsigned int>( this->m_InternalContainerSize );
    }
    
    /** Function to get a point from the data container. Do not use this one. */
    const MeasurementVectorType & GetMeasurementVector( const InstanceIdentifier &id ) const
    {
      return m_Dummy;
    };

    /** Function to get a point from the data container. */
    void GetMeasurementVector( const InstanceIdentifier &id, MeasurementVectorType & mv ) const;

    /** Function to set part of a point (measurement) in the data container. */
    void SetMeasurement( const InstanceIdentifier &id, const unsigned int &dim, const MeasurementType &value );

    /** Function to set a point (measurement vector) in the data container. */
    void SetMeasurementVector( const InstanceIdentifier &id, const MeasurementVectorType &mv );

    /** Function to get the frequency of point i. 1.0 if it exist, 0.0 otherwise. */
    FrequencyType GetFrequency( const InstanceIdentifier &id ) const;
    
    /** Function to get the total frequency. */
    TotalFrequencyType GetTotalFrequency() const
    {
      return static_cast<TotalFrequencyType>( this->m_InternalContainerSize );
    }

	protected:
		
		ListSampleCArray();
		virtual ~ListSampleCArray();
    void PrintSelf( std::ostream& os, Indent indent ) const;
		
	private:
		
		ListSampleCArray( const Self& );	// purposely not implemented
		void operator=( const Self& );    // purposely not implemented

    /** The internal storage of the data in a C array. */
    InternalDataContainerType   m_InternalContainer;
    InstanceIdentifier          m_InternalContainerSize;
    InstanceIdentifier          m_ActualSize;

    /** Dummy needed for GetMeasurementVector(), which we don't use. */
    MeasurementVectorType m_Dummy;

    /** Functions to (de)allocate the memory of the data container. */
    void AllocateInternalContainer( unsigned long size, unsigned int dim );
    void DeallocateInternalContainer( void );
				
	}; // end class ListSampleCArray
		
		
} // end namespace Statistics
} // end namespace itk


#ifndef ITK_MANUAL_INSTANTIATION
#include "itkListSampleCArray.txx"
#endif


#endif // end #ifndef __itkListSampleCArray_h

