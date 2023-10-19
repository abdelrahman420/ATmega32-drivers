

#include "../../LIB/STD.h"
#include "../../LIB/BitMath.h"
#include "INTERRUPT_INTERFACE.h"
#include "INTERRUPT_PRIVATE.h"
#include "INTERRUPT_CONFIG.h"


static void (*Global_PFNotif[3]) (void) = {NULL,NULL,NULL};
void Interrupt_voidInit(void)
{
	#if SenseControl_EXTI0 == EXTI_FallingEdge
		//Falling edge
		SET_BIT(MCUCR_REG,1);
		CLR_BIT(MCUCR_REG,0);
	#elif SenseControl_EXTI0 == EXTI_RisingEdge
		//Rising edge
		SET_BIT(MCUCR_REG,1);
		SET_BIT(MCUCR_REG,0);
	#elif SenseControl_EXTI0 == EXTI_OnChange
		//OnChange
		CLR_BIT(MCUCR_REG,1);
		SET_BIT(MCUCR_REG,0);
	#elif SenseControl_EXTI0 == EXTI_LowLevel
		//LowLevel
		CLR_BIT(MCUCR_REG,0);
		CLR_BIT(MCUCR_REG,1);
	#endif

	#if SenseControl_EXTI1 == EXTI_FallingEdge
		//Falling edge
		SET_BIT(MCUCR_REG,3);
		CLR_BIT(MCUCR_REG,2);
	#elif SenseControl_EXTI1 == EXTI_RisingEdge
		//Rising edge
		SET_BIT(MCUCR_REG,3);
		SET_BIT(MCUCR_REG,2);
	#elif SenseControl_EXTI1 == EXTI_OnChange
		//OnChange
		CLR_BIT(MCUCR_REG,3);
		SET_BIT(MCUCR_REG,2);
	#elif SenseControl_EXTI1 == EXTI_LowLevel
		//LowLevel
		CLR_BIT(MCUCR_REG,3);
		CLR_BIT(MCUCR_REG,2);
	#endif

	#if SenseControl_EXTI2 == EXTI_FallingEdge
		//Falling edge
		CLR_BIT(MCUCR_REG,6);
	#elif SenseControl_EXTI2 == EXTI_RisingEdge
		//Rising edge
		SET_BIT(MCUCR_REG,6);
	#endif

}

void Interrupt_voidChangeSenseControl(u8 copy_u8IntID,u8 copy_u8SenseControl)
{
	switch(copy_u8IntID)
	{
	case EXIT_INT0:
	{
		switch(copy_u8SenseControl)
		{
		case EXTI_FallingEdge:
		{
			SET_BIT(MCUCR_REG,1);
			CLR_BIT(MCUCR_REG,0);
		}
		break;
		case EXTI_RisingEdge:
		{
			SET_BIT(MCUCR_REG,1);
			SET_BIT(MCUCR_REG,0);
		}
		break;
		case EXTI_OnChange:
		{
			CLR_BIT(MCUCR_REG,1);
			SET_BIT(MCUCR_REG,0);
		}
		break;
		case EXTI_LowLevel:
		{
			CLR_BIT(MCUCR_REG,0);
			CLR_BIT(MCUCR_REG,1);
		}
		break;
		default:
			break;
		}
	}
	break;
	case EXIT_INT1:
	{
		switch(copy_u8SenseControl)
		{
		case EXTI_FallingEdge:
		{
			SET_BIT(MCUCR_REG,3);
			CLR_BIT(MCUCR_REG,2);
		}
		break;
		case EXTI_RisingEdge:
		{
			SET_BIT(MCUCR_REG,3);
			SET_BIT(MCUCR_REG,2);
		}
		break;
		case EXTI_OnChange:
		{
			CLR_BIT(MCUCR_REG,3);
			SET_BIT(MCUCR_REG,2);
		}
		break;
		case EXTI_LowLevel:
		{
			CLR_BIT(MCUCR_REG,3);
			CLR_BIT(MCUCR_REG,2);
		}
		break;
		default:
			break;
		}

	}
	break;
	case EXIT_INT2:
	{
		switch(copy_u8SenseControl)
		{
		case EXTI_FallingEdge:
		{
			CLR_BIT(MCUCSR_REG,6);

		}
		break;
		case EXTI_RisingEdge:
		{
			SET_BIT(MCUCSR_REG,6);
		}
		break;
		default:
		break;
		}
	}
	break;
	default:
	break;

	}

}
void EXTI_voidEnable(u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case EXIT_INT0:
	{
		SET_BIT(GICR_REG,EXTI_INT0_BIT);
	}
	break;
	case EXIT_INT1:
	{
		SET_BIT(GICR_REG,EXTI_INT1_BIT);
	}
	break;
	case EXIT_INT2:
	{
		SET_BIT(GICR_REG,EXTI_INT2_BIT);
	}
	break;
	default:
		break;
	}
}
void EXTI_voidDisable(u8 copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case EXIT_INT0:
	{
		CLR_BIT(GICR_REG,EXTI_INT0_BIT);
	}
	break;
	case EXIT_INT1:
	{
		CLR_BIT(GICR_REG,EXTI_INT1_BIT);
	}
	break;
	case EXIT_INT2:
	{
		CLR_BIT(GICR_REG,EXTI_INT2_BIT);
	}
	break;
	default:
		break;
	}
}
void Interrupt_voiSetCallBack(u8 copy_u8IntID,void (*PF) (void))
{
	if (PF != NULL)
	{
		switch (copy_u8IntID)
		{
		case EXIT_INT0:Global_PFNotif[0] = PF;
		break;
		case EXIT_INT1:Global_PFNotif[1] = PF;
		break;
		case EXIT_INT2:Global_PFNotif[2] = PF;
		break;
		default:
			break;
		}
	}
}
//ISR for INT0
void __vector_1	(void)	__attribute__((signal));
void __vector_1	(void)
{
	if(Global_PFNotif[0] != NULL)
	{
		Global_PFNotif[0]();
	}
}
//ISR for INT1
void __vector_2	(void)	__attribute__((signal));
void __vector_2	(void)
{
	if(Global_PFNotif[1] != NULL)
	{
		Global_PFNotif[1]();
	}
}
//ISR for INT2
void __vector_3	(void)	__attribute__((signal));
void __vector_3	(void)
{
	if(Global_PFNotif[2] != NULL)
	{
		Global_PFNotif[2]();
	}
}






