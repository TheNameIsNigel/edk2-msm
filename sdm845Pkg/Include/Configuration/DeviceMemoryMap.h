#ifndef _DEVICE_MEMORY_MAP_H_
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 95

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES                               \
  EFI_RESOURCE_ATTRIBUTE_PRESENT | EFI_RESOURCE_ATTRIBUTE_INITIALIZED |        \
      EFI_RESOURCE_ATTRIBUTE_TESTED | EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |     \
      EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |                               \
      EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |                         \
      EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |                            \
      EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE

typedef enum { NoHob, AddMem, AddDev, MaxMem } DeviceMemoryAddHob;

typedef struct {
  EFI_PHYSICAL_ADDRESS         Address;
  UINT64                       Length;
  EFI_RESOURCE_TYPE            ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  ARM_MEMORY_REGION_ATTRIBUTES ArmAttributes;
  DeviceMemoryAddHob           HobOption;
  EFI_MEMORY_TYPE              MemoryType;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Address,	  Length,     ResourceType, Resource Attribute, ARM MMU
       Attribute,                  HobOption, EFI Memory Type */

    /* DDR */

    /* Kernel */
    {0x80000000, 0x01AC0000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesCode},
    /* HLOS1 */
    {0x81AC0000, 0x03C40000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData},
    /* MPSS_EFS */
    {0x85D00000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddMem, EfiReservedMemoryType},
    /* GPU PRR */
    {0x85F00000, 0x00010000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddMem, EfiReservedMemoryType},
    /* HLOS2 */
    {0x85F10000, 0x000B0000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData},
    /* AOP CMD DB */
    {0x85FE0000, 0x00020000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiReservedMemoryType},
    /* SMEM */
    {0x86000000, 0x00200000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiReservedMemoryType},
    /* TZApps */
    {0x86D00000, 0x00E00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, NoHob, EfiReservedMemoryType},
    /* TGCM */
    {0x8B500000, 0x00A00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddMem, EfiReservedMemoryType},
#ifdef XIAOMI_PIL_FIXED
    /* PIL_REGION */
    {0x8BF00000, 0x0C100000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddMem, EfiReservedMemoryType},
    /* DXE Heap */
    {0x98000000, 0x05330000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory},
#else
    /* PIL_REGION */
    {0x8BF00000, 0x0BD00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_DEVICE, AddMem, EfiReservedMemoryType},
    /* DXE Heap */
    {0x97C00000, 0x05730000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory},
#endif
    /* DBI Dump */
    {0x9D330000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     NoHob, EfiConventionalMemory},
    /* FrameBuffer */
    {0x9D400000, 0x02400000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH, AddMem, EfiReservedMemoryType},
    /* FV Region */
    {0x9F800000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData},
    /* ABOOT FV */
    {0x9FA00000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiReservedMemoryType},
    /* UEFI FD */
    {0x9FC00000, 0x00300000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData},
    /* SEC Heap */
    {0x9FF00000, 0x0008C000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData},
    /* CPU Vectors */
    {0x9FF8C000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData},
    /* MMU PageTables */
    {0x9FF8D000, 0x00003000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData},
    /* UEFI Stack */
    {0x9FF90000, 0x00040000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiBootServicesData},

    {0x9FFD0000, 0x0000A000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiRuntimeServicesData},
    {0x9FFDA000, 0x00003000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiRuntimeServicesData},
    {0x9FFDD000, 0x00004000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiRuntimeServicesData},
    {0x9FFE1000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiRuntimeServicesData},
    {0x9FFE2000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiRuntimeServicesData},
    {0x9FFE3000, 0x00014000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiRuntimeServicesData},
    {0x9FFF7000, 0x00008000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiRuntimeServicesData},
    {0x9FFFF000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED, AddMem,
     EfiRuntimeServicesData},

#ifdef MEMORY_4G
    {0xA0000000, 0xDDFA0000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory},
#else
#ifdef MEMORY_8G
    {0xA0000000, 0xE0000000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory},
    {0x180000000, 0xFC8A0000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory},
#else
#ifdef MEMORY_10G
    {0xA0000000, 0x254AC0000, EFI_RESOURCE_SYSTEM_MEMORY,
    SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
    ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory},
#else
    {0xA0000000, 0x15AE00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES,
     ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK, AddMem, EfiConventionalMemory},

#endif
#endif
#endif

    /* Other */

    /* AOP_SS_MSG_RAM */
    {0x0C300000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     NoHob, EfiConventionalMemory},
    /* IMEM Base */
    {0x14680000, 0x0003F000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     NoHob, EfiConventionalMemory},
    /* IMEM Cookie Base */
    {0x146BF000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiConventionalMemory},

    /* Register */

    /* GCC CLK CTL */
    {0x00100000, 0x000B0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* SECURITY CONTROL */
    {0x00780000, 0x00007000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PRNG_CFG_PRNG */
    {0x00790000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* QUPV3_0_GSI */
    {0x00800000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* QUPV3_1_GSI */
    {0x00A00000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PCIE_0_WRAPPER_AHB */
    {0x01C00000, 0x00008000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PCIE_1_WRAPPER_AHB */
    {0x01C08000, 0x00008000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* UFS UFS REGS */
    {0x01D80000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* CRYPTO0 CRYPTO */
    {0x01DC0000, 0x00040000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TCSR_TCSR_REGS */
    {0x01FC0000, 0x00030000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TLMM_EAST */
    {0x03500000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TLMM_NORTH */
    {0x03900000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TLMM_SOUTH */
    {0x03D00000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},

    /* GPU_CPR */
    {0x0509A000, 0x00004000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},

    /* RPMH_CPRF */
    {0x0C200000, 0x0000F000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* GPU_GMU_GX_BLK */
    {0x0506A000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},

    /* GPU_GMU_CX_BLK */
    {0x0507D000, 0x0000C000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* GPU_CC */
    {0x05090000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* GPU_ISENSE */
    {0x0508B000, 0x00002000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* QUPV3_SSC_GSI */
    {0x05A00000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PERIPH_SS */
    {0x08800000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* USB30_PRIM */
    {0x0A600000, 0x0011B000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* VIDEO_CC */
    {0x0AB00000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TITAN_A_CCI */
    {0x0AC4A000, 0x00004000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TITAN_CAM_CC */
    {0x0AD00000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* MDSS */
    {0x0AE00000, 0x00134000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* DISP_CC */
    {0x0AF00000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PDC_DISPLAY */
    {0x0B290000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PDC_DISP_SEQ */
    {0x0B490000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* RPMH_BCM_BCM_TOP */
    {0x0BA00000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* SLP_CNTR */
    {0x0C221000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TSENS0 */
    {0x0C222000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TSENS1 */
    {0x0C223000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TSENS0_TM */
    {0x0C263000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PSHOLD */
    {0x0C264000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* TSENS1_TM */
    {0x0C265000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PMIC_ARB_SPMI */
    {0x0C400000, 0x02800000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* SMMU */
    {0x15000000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* GOLD_SAW4_SRM */
    {0x17830000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* SILVER_SAW4_SRM */
    {0x17840000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* GOLD_CLK_CTL */
    {0x178B0000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* SILVER_CLK_CTL */
    {0x178C0000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* L3_CLK_CTL */
    {0x178D0000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* APSS_WDT_TMR1 */
    {0x17980000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* APSS_IPC_INT */
    {0x17990000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* APSS_RSC_RSCCR */
    {0x179C0000, 0x00030000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* APSS_GIC500_GICD */
    {0x17A00000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* APSS_GIC500_GICR */
    {0x17A60000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* QTIMER */
    {0x17C00000, 0x00110000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* OSM */
    {0x17D20000, 0x000B0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PCIE_1_WRAPPER_AXI */
    {0x40000000, 0x02000000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* PCIE_0_WRAPPER_AXI */
    {0x60000000, 0x01000000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* Terminator */
    {}};

#endif
