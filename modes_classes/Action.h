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
    UndoUnixEncoder,
    FusionOrbitXEncoder,
    FusionOrbitYEncoder,
    FusionOrbitXYEncoder,
    FusionOrbitXYInvertedEncoder,

    ModeSelectionEncoderAction,

    // actions for buttons

    PlayPouseAction,
    PreviousTrackAction,
    NextTrackAction,
    MuteAction,

    SwitchUndoStyleAction,

    SwitchModeToMouseXAction,
    SwitchModeToMouseYAction,
    SwitchModeToMouseScrollXAction,
    SwitchModeToMouseScrollYAction,
    SwitchModeToMouseDragXAction,
    SwitchModeToMouseDragYAction,

    SwitchModeToArrowsXAction,
    SwitchModeToArrowsYAction,

    SwithcModeToFusionXModeAction,
    SwithcModeToFusionYModeAction,

    SwitchMouseAxisAction,
    SwitchMouseStyleToRegularAction,
    SwitchMouseStyleToScrollAction,
    SwitchMouseStyleToDragAction
};

#endif