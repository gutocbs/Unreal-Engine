// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ESCAPEROOM_Grabber_generated_h
#error "Grabber.generated.h already included, missing '#pragma once' in Grabber.h"
#endif
#define ESCAPEROOM_Grabber_generated_h

#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_SPARSE_DATA
#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_RPC_WRAPPERS
#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGrabber(); \
	friend struct Z_Construct_UClass_UGrabber_Statics; \
public: \
	DECLARE_CLASS(UGrabber, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeRoom"), NO_API) \
	DECLARE_SERIALIZER(UGrabber)


#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUGrabber(); \
	friend struct Z_Construct_UClass_UGrabber_Statics; \
public: \
	DECLARE_CLASS(UGrabber, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/EscapeRoom"), NO_API) \
	DECLARE_SERIALIZER(UGrabber)


#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGrabber(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGrabber) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGrabber); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGrabber); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGrabber(UGrabber&&); \
	NO_API UGrabber(const UGrabber&); \
public:


#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGrabber(UGrabber&&); \
	NO_API UGrabber(const UGrabber&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGrabber); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGrabber); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGrabber)


#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Reach() { return STRUCT_OFFSET(UGrabber, Reach); }


#define EscapeRoom_Source_EscapeRoom_Grabber_h_12_PROLOG
#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_PRIVATE_PROPERTY_OFFSET \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_SPARSE_DATA \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_RPC_WRAPPERS \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_INCLASS \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define EscapeRoom_Source_EscapeRoom_Grabber_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_PRIVATE_PROPERTY_OFFSET \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_SPARSE_DATA \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_INCLASS_NO_PURE_DECLS \
	EscapeRoom_Source_EscapeRoom_Grabber_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ESCAPEROOM_API UClass* StaticClass<class UGrabber>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID EscapeRoom_Source_EscapeRoom_Grabber_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
