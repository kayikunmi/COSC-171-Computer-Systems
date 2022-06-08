// ==============================================================================
/**
 * mmu.c
 */
// ==============================================================================



// ==============================================================================
// INCLUDES

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "mmu.h"
#include "vmsim.h"
// ==============================================================================



// ==============================================================================
// MACROS AND GLOBALS

/** 
 * The (real) address of the upper page table.  Initialized by a call
 * to `mmu_init()`.
 */
static vmsim_addr_t upper_pt_addr = 0;


// ==============================================================================



// ==============================================================================
void
mmu_init (vmsim_addr_t new_upper_pt_addr) {

  upper_pt_addr = new_upper_pt_addr;
  
}
// ==============================================================================



// ==============================================================================
vmsim_addr_t 
mmu_translate (vmsim_addr_t sim_addr) {

// REPLACE THIS WITH YOUR OWN, FULL IMPLEMENTATION OF THIS FUNCTION.
 uint32_t phys_addr;
 uint32_t buffer;
 uint32_t lowbuffer;
 
 uint32_t offset =  upper_pt_addr & 0xfff; //offset
 uint32_t upperindex = (upper_pt_addr >> 22) & 0x3ff; //UPT
 uint32_t lowerindex = ( upper_pt_addr >> 12) & 0x3ff; //LPT

uint32_t pointer_index = upper_pt_addr + upperindex << 2;
vmsim_read_real (&buffer, pointer_index, sizeof(buffer));
 if (buffer= 0)
   {
      vmsim_map_fault(sim_addr); //call vsim
      mmu_translate(sim_addr);
    }

 uint32_t point_in = upper_pt_addr + lowerindex << 2;
 vmsim_read_real (&lowbuffer, point_in, sizeof(lowbuffer));
 if (buffer != 0 && lowbuffer == 0)
    {
      vmsim_map_fault(sim_addr);//call vmsim
      mmu_translate(sim_addr);
	
    }
  if (buffer != 0 && lowbuffer != 0)
    {
      phys_addr = lowbuffer + offset;
    }
  
  return phys_addr;
  
}
// ==============================================================================
