@extends('layouts.master')

@section('content')
    <div class="row">
        <div class="">
            <h1 class="pt-5">Sign In</h1>
            @if(count($errors) > 0)
                <div class="alert alert-danger">
                    @foreach($errors->all() as $error)
                        <p>{{ $error }}</p>
                    @endforeach
                </div>
            @endif
            <form action="{{ route('user.signin') }}" method="post">
                <div class="form-group pt-3">
                    <label for="email">Email Address</label>
                    <input type="text" id="email" name="email" placeholder="Email Address" class="form-control" style="width: 30%">
                </div>
                <div class="form-group pt-3 pb-4">
                    <label for="password">Password</label>
                    <input type="password" id="password" name="password" placeholder="Password" class="form-control" style="width: 30%">
                </div>
                <button type="submit" class="btn btn-primary">Sign In</button>
                {{ csrf_field() }}
            </form>
        </div>
    </div>
@endsection
