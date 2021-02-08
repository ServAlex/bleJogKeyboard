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

    VolumeEncoder,

    // timed action
    TabSwitchEncoder,
    ZooomEncoder,
    AltTabEncoder,
    MouseDragXEncoder,
    MouseDragYEncoder,
    UndoEncoder,
    FusionOrbitXEncoder,
    FusionOrbitYEncoder,
    FusionOrbitXYEncoder,
    FusionOrbitXYInvertedEncoder,

    ModeSelectionEncoderAction
};

#endif