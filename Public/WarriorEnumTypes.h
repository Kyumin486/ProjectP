#pragma once

UENUM()
enum class EWarriorConfirmType : uint8
{
	Yes,
	No,
};

UENUM()
enum class EWarriorValidType : uint8
{
	Valid,
	InValid,
};

UENUM()
enum class EWarriorSuccessType : uint8
{
	Successful,
	Failed,
};

UENUM()
enum class EWarriorInputMode : uint8
{
	GameOnly,
	UIOnly,
};

UENUM(BlueprintType)
enum class EWarriorBGM : uint8
{
	Normal,
	Rampage,
	Sevarog,
	End,
};