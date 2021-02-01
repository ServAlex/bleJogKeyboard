#ifndef ActionsEnum_h
#define ActionsEnum_h

enum Action
{
    None,

    StartModeSelection,
    ConfirmModeSelection,

    // implemented
    ArrowsXEncoderAction,
    ArrowsYEncoderAction,
    MouseXEncoderAction,
    MouseYEncoderAction,
    MouseScrollXEncoderAction,
    MouseScrollYEncoderAction,

    TabSwitchEncoder,
    VolumeEncoder,
    ZooomEncoder,
    AltTabEncoder,

    // pending without timed action
    // timed action
    MouseDragXEncoder,
    MouseDragYEncoder,
    UndoEncoder,

    ModeSelectionEncoderAction
};

#endif